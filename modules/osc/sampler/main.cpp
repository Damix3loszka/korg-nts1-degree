/**
    Guillaume Elias 2020. Use this file at your own peril.
    This project is under BSD3 license. See LICENSE file.
*/
// #include "sampler.h"
//#include "sampler.h"

#include "sampler.h"
#include "userosc.h"

sampler samp = sampler();

void OSC_INIT(uint32_t platform, uint32_t api)
{
}

void OSC_CYCLE(const user_osc_param_t *const params, int32_t *yn, const uint32_t frames)
{

    q31_t *__restrict y = (q31_t *)yn;

    const q31_t *y_e = y + frames;

    for (; y != y_e;)
    {

        const float sig = samp.next_sample();

        *(y++) = f32_to_q31(sig);
    }
}

void OSC_NOTEON(const user_osc_param_t *const params)
{
    samp.start((params->pitch) >> 8);
}

void OSC_NOTEOFF(const user_osc_param_t *const params)
{
    (void)params;
    samp.stop();
}

void OSC_PARAM(uint16_t index, uint16_t value)
{
    switch (index)
    {
    case k_user_osc_param_id1:
        break;
    case k_user_osc_param_shape:
        break;
    case k_user_osc_param_shiftshape:
    default:
        break;
    }
}
