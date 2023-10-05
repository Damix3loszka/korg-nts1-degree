
#include "dsp/delayline.hpp"
#include "userdelfx.h"
#include <cmath>
#define k_samplerate 48000
#define LINE_LENGTH 65536

__sdram f32pair_t delay_arr[LINE_LENGTH] = {};

dsp::DualDelayLine delay_line;
float feedback = 0.5f;
float offset_magnitude = 1.f;
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

        f32pair_t delayed_lr_samples = delay_line.readFrac(k_samplerate * offset_magnitude);

        delay_line.write(f32pair_add(in_lr_samples, f32pair_mulscal(delayed_lr_samples, feedback)));

        float out_l_sample = in_lr_samples.a * (1.f - mix) + delayed_lr_samples.a * mix;
        float out_r_sample = in_lr_samples.b * (1.f - mix) + delayed_lr_samples.b * mix;
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
        offset_magnitude = valf;
        break;

    case k_user_delfx_param_depth:
        feedback = valf * 0.7f + 0.1f;
        break;

    case k_user_delfx_param_shift_depth:
        mix = valf;
        break;

    default:
        break;
    }
}