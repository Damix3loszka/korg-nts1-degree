#include "userdelfx.h"

#define k_samplerate 48000
#define LINE_LENGTH 65536
#define LINE_MASK LINE_LENGTH - 1

unsigned int write_index = 0;
unsigned int read_index = LINE_MASK - k_samplerate;

__sdram float delay_l[LINE_LENGTH] = {};
__sdram float delay_r[LINE_LENGTH] = {};
void DELFX_INIT(uint32_t platform, uint32_t api)
{
}

void DELFX_PROCESS(float *xn, uint32_t frames)
{
    float *__restrict in = xn;
    float samples = frames * 2;
    for (uint32_t i = 0; i < frames; ++i)
    {
        float in_l_sample = in[2 * i];
        float in_r_sample = in[2 * i + 1];

        float delayed_l_sample = delay_l[read_index];
        float delayed_r_sample = delay_r[read_index];

        delay_l[write_index] = in_l_sample + 0.3f * delayed_l_sample;
        delay_r[write_index] = in_r_sample + 0.3f * delayed_r_sample;

        write_index = ++write_index & LINE_MASK;
        read_index = ++read_index & LINE_MASK;

        in[2 * i] = in_l_sample * 0.3f + delayed_l_sample * 0.7f;
        in[2 * i + 1] = in_r_sample * 0.3f + delayed_r_sample * 0.7f;
    }
}

void DELFX_PARAM(uint8_t index, int32_t value)
{
    const float valf = q31_to_f32(value);
    const float sample_offest = k_samplerate * (1.f - valf);
    switch (index)
    {
    case k_user_delfx_param_time:

        read_index = write_index - sample_offest;
        if (read_index < 0)
        {
            read_index += LINE_MASK;
        }
        break;

    case k_user_delfx_param_depth:
        break;

    case k_user_delfx_param_shift_depth:

        break;

    default:
        break;
    }
}