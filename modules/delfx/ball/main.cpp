#include "userdelfx.h"

#define k_samplerate 48000
#define LINE_LENGTH 65536
#define LINE_MASK LINE_LENGTH - 1
__sdram float delay_l[LINE_LENGTH] = {};
__sdram float delay_r[LINE_LENGTH] = {};

uint32_t write_index = 0;
uint32_t read_index = LINE_MASK - k_samplerate;
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
    }
}

void DELFX_PARAM(uint8_t index, int32_t value)
{
    const float valf = q31_to_f32(value);
    switch (index)
    {
    case k_user_delfx_param_time:

        break;

    case k_user_delfx_param_depth:
        break;

    case k_user_delfx_param_shift_depth:

        break;

    default:
        break;
    }
}