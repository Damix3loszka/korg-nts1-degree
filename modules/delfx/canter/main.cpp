
#include "dsp/delayline.hpp"
#include "userdelfx.h"
#include <cmath>
#define k_samplerate 48000
#define LINE_LENGTH 65536

__sdram f32pair_t delay_arr[LINE_LENGTH] = {};

dsp::DualDelayLine delay_line;
float pace = 1.f;
float clop_speed = 0.12;
float feedback = 0.5f;
float mix = 0.5f;

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

        f32pair_t delayed_lr_samples_main = delay_line.readFrac(k_samplerate * pace);
        f32pair_t delayed_lr_samples_aux = delayed_lr_samples_main;

        for (uint8_t o = 0; o < 2; ++o)
        {
            f32pair_t delayed_lr_sample = delay_line.readFrac(k_samplerate * (pace + clop_speed / 2 + o * clop_speed));
            delayed_lr_samples_aux = f32pair_add(delayed_lr_samples_aux, delayed_lr_sample);
        }

        delayed_lr_samples_aux = f32pair_mulscal(delayed_lr_samples_aux, 0.33f);

        delay_line.write(f32pair_add(in_lr_samples, f32pair_mulscal(delayed_lr_samples_main, feedback)));

        float out_l_sample = in_lr_samples.a * (1.f - mix) + delayed_lr_samples_aux.a * mix;
        float out_r_sample = in_lr_samples.b * (1.f - mix) + delayed_lr_samples_aux.b * mix;
        in[2 * i] = out_l_sample;
        in[2 * i + 1] = out_r_sample;
    }
}

void DELFX_PARAM(uint8_t index, int32_t value)
{
    const float valf = q31_to_f32(value);

    switch (index)
    {
    case k_user_delfx_param_time:;
        pace = 1.f - (valf * 0.4f + 0.3f);
        clop_speed = 0.1f + (1.f - (valf * 0.8f + 0.1f)) * 0.01f;

        break;

    case k_user_delfx_param_depth:

        feedback = valf * 0.4f + 0.2f;
        break;

    case k_user_delfx_param_shift_depth:
        mix = valf;
        break;

    default:
        break;
    }
}