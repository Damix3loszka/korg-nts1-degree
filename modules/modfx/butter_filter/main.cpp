/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include "butter_filter.h"
#include "usermodfx.h"

butter_filter filter_l, filter_r;

void MODFX_INIT(uint32_t platform, uint32_t api)
{
    filter_l.set_cutoff_freq(1);
    filter_r.set_cutoff_freq(1);
};

void MODFX_PROCESS(const float *main_xn, float *main_yn, const float *sub_xn, float *sub_yn, uint32_t frames)
{
    float x_l = 0, x_r = 0;
    for (int i = 0; i < frames; ++i)
    {
        x_l = main_xn[2 * i];
        x_r = main_xn[2 * i + 1];

        main_yn[2 * i] = filter_l.process_sample(x_l);
        main_yn[2 * i + 1] = filter_r.process_sample(x_r);
    }
};

void MODFX_PARAM(uint8_t index, int32_t value)
{
    const float valf = q31_to_f32(value);
    switch (index)
    {
    case k_user_modfx_param_time:
        filter_l.set_cutoff_freq(valf);
        filter_r.set_cutoff_freq(valf);
        break;
    case k_user_modfx_param_depth:
        filter_l.set_filter_properties(valf);
        filter_r.set_filter_properties(valf);
    default:
        break;
    };
}
