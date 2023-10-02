#include "usermodfx.h"
#include <algorithm>
#include <array>
#include <math.h>
#define k_samplerate_recipf (2.08333333333333e-005f)
#define k_samplerate 48000
#define k_samplerate_2 24000
enum TYPE
{
    LP,
    HP
};
class butter_filter
{
  public:
    float process_sample(float sample);
    void set_cutoff_freq(float frac);
    void set_filter_properties(float frac);

  private:
    float process_sample_o1(float sample);
    float process_sample_o2(float sample);
    float process_sample_o3(float sample);
    float passband_freq;
    float delay_x[3] = {0, 0, 0};
    float delay_y[3] = {0, 0, 0};
    float cutoff_frequency = 0.f;
    float analog_frequency = 0.f;
    float o_3_coeff_1 = 2;
    float o_3_coeff_2 = 2;
    float o_2_coeff = M_SQRT2;
    uint8_t filter_order = 2;
    TYPE filter_type = LP;
};

inline float butter_filter::process_sample(float sample)
{
    float out = 0;
    switch (filter_order)
    {
    case 1:
        out = process_sample_o1(sample);
        break;
    case 2:
        out = process_sample_o2(sample);
        break;
    case 3:
        out = process_sample_o3(sample);
        break;
    }
    return out;
}

inline void butter_filter::set_cutoff_freq(float frac)
{
    cutoff_frequency = k_samplerate_2 * frac;
    if (filter_order == 3)
    {
        cutoff_frequency = cutoff_frequency < 300 ? 300 : cutoff_frequency;
    }
    analog_frequency = fasttanf(cutoff_frequency * k_samplerate_recipf / 2);
}

inline void butter_filter::set_filter_properties(float frac)
{
    float val = frac - 0.5f;
    if (val < 0)
        filter_type = LP;
    else
        filter_type = HP;

    float abs_val = fabsf(val);

    if (abs_val > 0.333f)
        filter_order = 3;
    else if (abs_val > 0.166f)
    {
        filter_order = 2;
    }
    else
        filter_order = 1;

    for (uint8_t i = 0; i < 3; ++i)
    {
        delay_x[i] = 0;
        delay_y[i] = 0;
    }
}

inline float butter_filter::process_sample_o2(float sample)
{
    float wa = analog_frequency;
    float wa2 = wa * wa;
    float one_y_coeff = 1 + wa * o_2_coeff + wa2;
    float z2_coefficient = one_y_coeff - wa * M_SQRT2 * 2;

    float x = 0;
    if (filter_type == LP)
    {
        x = sample + 2 * delay_x[0] + delay_x[1];
        x *= (wa2 / one_y_coeff);
    }
    else
    {
        x = sample - 2 * delay_x[0] + delay_x[1];
        x *= (1 / one_y_coeff);
    }

    float out = x - ((2 * (wa2 - 1) * delay_y[0] + z2_coefficient * delay_y[1]) / one_y_coeff);

    std::swap(delay_x[0], delay_x[1]);
    std::swap(delay_y[0], delay_y[1]);
    delay_x[0] = sample;
    delay_y[0] = out;

    return out;
}
inline float butter_filter::process_sample_o1(float sample)
{
    float wa = analog_frequency;

    float x = 1;
    if (filter_type == LP)
    {
        x = sample + delay_x[0];
        x *= (wa / (wa + 1));
    }
    else
    {
        x = sample - delay_x[0];
        x *= (1 / (wa + 1));
    }
    float out = x - ((wa - 1) / (wa + 1) * delay_y[0]);
    delay_x[0] = sample;
    delay_y[0] = out;
    return out;
}
inline float butter_filter::process_sample_o3(float sample)
{
    float wa = analog_frequency;
    float wa2 = wa * wa;
    float wa3 = wa2 * wa;

    float one_y_coeff = wa3 + o_3_coeff_2 * wa2 + o_3_coeff_1 * wa + 1;
    float z_y_coeff = one_y_coeff + 2 * wa3 - 2 * o_3_coeff_1 * wa - 4;
    float z2_y_coeff = one_y_coeff + 2 * wa3 - 2 * o_3_coeff_2 * wa2 - 2 * o_3_coeff_1 * wa + 2;
    float z3_y_coeff = one_y_coeff - 2 * o_3_coeff_2 * wa2 - 2;

    float x = 0;
    if (filter_type == LP)
    {
        x = sample + 3 * delay_x[0] + 3 * delay_x[1] + delay_x[2];
        x *= (wa3 / one_y_coeff);
    }
    else
    {
        x = sample - 3 * delay_x[0] + 3 * delay_x[1] - delay_x[2];
        x *= (1 / one_y_coeff);
    }

    float out = x - ((z_y_coeff * delay_y[0] + z2_y_coeff * delay_y[1] + z3_y_coeff * delay_y[2]) / one_y_coeff);

    std::swap(delay_x[2], delay_x[1]);
    std::swap(delay_x[0], delay_x[1]);

    std::swap(delay_y[2], delay_y[1]);
    std::swap(delay_y[0], delay_y[1]);

    delay_x[0] = sample;
    delay_y[0] = out;
    return out;
}