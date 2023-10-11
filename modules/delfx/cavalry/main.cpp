
#include "dsp/delayline.hpp"
#include "userdelfx.h"
#include <cmath>
#define k_samplerate 48000
#define LINE_LENGTH 65536

__sdram f32pair_t delay_arr[LINE_LENGTH] = {};

dsp::DualDelayLine delay_line;
uint8_t number_of_horses = 1;
float delay_magnitude = 1.f;
float feedback = (delay_magnitude * 2.f * 5 + number_of_horses / 5.f * 2) / 7.f * 0.7f - 0.1f;
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

        f32pair_t delayed_lr_samples_aux = {0, 0};
        f32pair_t delayed_lr_samples_aux_out = {0, 0};

        for (uint8_t i = 0; i < number_of_horses; ++i)
        {
            f32pair_t delayed_lr_samples_main = delay_line.readFrac(k_samplerate * (delay_magnitude + i * 0.1f));
            f32pair_t delayed_lr_samples_aux = delayed_lr_samples_main;

            for (uint8_t o = 0; o < 2; ++o)
            {
                f32pair_t delayed_lr_sample =
                    delay_line.readFrac(k_samplerate * (delay_magnitude + i * 0.1f + 0.12f + o * 0.6f));
                delayed_lr_samples_aux = f32pair_add(delayed_lr_samples_aux, delayed_lr_sample);
            }
            in_lr_samples delayed_lr_samples_aux_out = f32pair_add(delayed_lr_samples_aux_out, delayed_lr_samples_aux);
        }
        delayed_lr_samples_aux_out = f32pair_mulscal(delayed_lr_samples_aux_out, 1 / number_of_horses * 0.33f);
        f32pair_t delayed_lr_samples_main = delay_line.readFrac(k_samplerate * delay_magnitude);
        delay_line.write(f32pair_add(in_lr_samples, f32pair_mulscal(delayed_lr_samples_main, feedback)));

        float out_l_sample = in_lr_samples.a * (1.f - mix) + delayed_lr_samples_aux_out.a * mix;
        float out_r_sample = in_lr_samples.b * (1.f - mix) + delayed_lr_samples_aux_out.b * mix;
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
        delay_magnitude = valf * 0.2f + 0.3f;
        feedback = (delay_magnitude * 2.f * 5 + number_of_horses / 5.f * 2) / 7.f * 0.7f - 0.1f;
        break;

    case k_user_delfx_param_depth:
        number_of_horses = valf * 0.99f * 5 + 1;

        feedback = (delay_magnitude * 2.f * 5 + number_of_horses / 5.f * 2) / 7.f * 0.7f - 0.1f;
        break;

    case k_user_delfx_param_shift_depth:
        mix = valf;
        break;

    default:
        break;
    }
}