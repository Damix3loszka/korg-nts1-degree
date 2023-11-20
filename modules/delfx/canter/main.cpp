#include "dsp/delayline.hpp"
#include "userdelfx.h"
#define k_samplerate 48000
#define LINE_LENGTH 65536
f32pair_t operator+(const f32pair_t &l, const f32pair_t &r);
f32pair_t operator*(const f32pair_t &l, const f32pair_t &r);
f32pair_t operator*(const f32pair_t &l, const float &r);
f32pair_t &operator+=(f32pair_t &l, const f32pair_t &r);
f32pair_t &operator*=(f32pair_t &l, const float &r);

__sdram f32pair_t delay_arr[LINE_LENGTH] = {};

dsp::DualDelayLine delay_line;
float sequence_interval = 1.f * k_samplerate;
float step_interval = 0.12f * k_samplerate;
float feedback = 0.5f;
float drywet = 0.5f;

void DELFX_INIT(uint32_t platform, uint32_t api)
{
    delay_line.setMemory(delay_arr, LINE_LENGTH);
}

void DELFX_PROCESS(float *xn, uint32_t frames)
{
    float *__restrict in = xn;

    for (uint8_t i = 0; i < frames; ++i)
    {
        float in_l_sample = in[2 * i];
        float in_r_sample = in[2 * i + 1];

        f32pair_t in_lr_samples = f32pair_t{in_l_sample, in_r_sample};

        f32pair_t delayed_lr_samples_main = delay_line.readFrac(sequence_interval);
        f32pair_t delayed_lr_samples_aux = delayed_lr_samples_main;

        delayed_lr_samples_aux += delay_line.readFrac(sequence_interval + step_interval / 2);
        delayed_lr_samples_aux += delay_line.readFrac(sequence_interval + step_interval / 2 + step_interval);

        delayed_lr_samples_aux *= 0.33f;

        delay_line.write(in_lr_samples + delayed_lr_samples_main * feedback);

        f32pair_t out_lr_samples = in_lr_samples * (1.f - drywet) + delayed_lr_samples_aux * drywet;
        in[2 * i] = out_lr_samples.a;
        in[2 * i + 1] = out_lr_samples.b;
    }
}

void DELFX_PARAM(uint8_t index, int32_t value)
{
    const float valf = q31_to_f32(value);

    switch (index)
    {
    case k_user_delfx_param_time:
        sequence_interval = (1.f - (valf * 0.4f + 0.3f)) * k_samplerate;
        step_interval = (0.1f + (1.f - (valf * 0.8f + 0.1f)) * 0.01f) * k_samplerate;
        break;

    case k_user_delfx_param_depth:
        feedback = valf * 0.4f + 0.2f;
        break;

    case k_user_delfx_param_shift_depth:
        drywet = valf;
        break;

    default:
        break;
    }
}

f32pair_t operator+(const f32pair_t &l, const f32pair_t &r)
{
    f32pair_t temp;
    temp.a = l.a + r.a;
    temp.b = l.b + r.b;
    return temp;
}

f32pair_t operator*(const f32pair_t &l, const f32pair_t &r)
{
    f32pair_t temp;
    temp.a = l.a * r.a;
    temp.b = l.b * r.b;
    return temp;
}

f32pair_t operator*(const f32pair_t &l, const float &r)
{
    f32pair_t temp;
    temp.a = l.a * r;
    temp.b = l.b * r;
    return temp;
}

f32pair_t &operator+=(f32pair_t &l, const f32pair_t &r)
{
    l.a += r.a;
    l.b += r.b;
}

f32pair_t &operator*=(f32pair_t &l, const float &r)
{
    l.a *= r;
    l.b *= r;
}
