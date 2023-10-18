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
struct coeffs
{
    float z_y[4] = {0, 0, 0, 0};
    float z_x = 0;
    void recalculate(uint8_t order, float cutoff_frequency, TYPE type)
    {
        float cutoff_frequency1 = fasttanf(cutoff_frequency * k_samplerate_recipf / 2);
        float cutoff_frequency2 = fastpowf(cutoff_frequency1, 2);
        float cutoff_frequency3 = fastpowf(cutoff_frequency1, 3);
        for (uint8_t i = 0; i < 4; ++i)
        {
            z_y[i] = 0;
        }
        switch (order)
        {
        case 1:
            z_y[0] = cutoff_frequency1 + 1;
            z_y[1] = cutoff_frequency1 - 1;
            break;
        case 2:
            z_y[0] = cutoff_frequency2 + cutoff_frequency1 * M_SQRT2 + 1;
            z_y[1] = cutoff_frequency2 - 1;
            z_y[2] = cutoff_frequency2 - cutoff_frequency1 * M_SQRT2 + 1;
            break;
        case 3:
            z_y[0] = cutoff_frequency3 + 2 * cutoff_frequency2 + 2 * cutoff_frequency1 + 1;
            z_y[1] = 3 * cutoff_frequency3 + 2 * cutoff_frequency2 - 2 * cutoff_frequency1 - 3;
            z_y[2] = 3 * cutoff_frequency3 - 2 * cutoff_frequency2 - 2 * cutoff_frequency1 + 3;
            z_y[3] = cutoff_frequency3 - 2 * cutoff_frequency2 + 2 * cutoff_frequency1 - 1;
            break;
        }

        z_x = 1;
        if (type == LP)
        {
            z_x = fastpowf(cutoff_frequency1, order);
        }
    };
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
    float delay_x[3] = {0, 0, 0};
    float delay_y[3] = {0, 0, 0};
    float cutoff_frequency = 0.f;
    uint8_t filter_order = 2;
    TYPE filter_type = LP;
    coeffs filter_coefficients;
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

    filter_coefficients.recalculate(filter_order, cutoff_frequency, filter_type);
}

inline void butter_filter::set_filter_properties(float frac)
{
    float val = frac - 0.5f;
    if (val < 0)
        filter_type = LP;
    else
        filter_type = HP;

    float abs_val = fabsf(val);

    uint8_t temp_filter_order = 0;
    if (abs_val > 0.333f)
        temp_filter_order = 3;
    else if (abs_val > 0.166f)
    {
        temp_filter_order = 2;
    }
    else
        temp_filter_order = 1;

    if (temp_filter_order != filter_order)
    {
        for (uint8_t i = 0; i < 3; ++i)
        {
            delay_x[i] = 0;
            delay_y[i] = 0;
        }
    }

    filter_order = temp_filter_order;

    filter_coefficients.recalculate(filter_order, cutoff_frequency, filter_type);
}
inline float butter_filter::process_sample_o1(float sample)
{
    float x = 0;
    if (filter_type == LP)
    {
        x = sample + delay_x[0];
    }
    else
    {
        x = sample - delay_x[0];
    }

    x *= filter_coefficients.z_x;
    float y = filter_coefficients.z_y[1] * delay_y[0];
    float out = (x - y) / filter_coefficients.z_y[0];
    delay_x[0] = sample;
    delay_y[0] = out;
    return out;
}
inline float butter_filter::process_sample_o2(float sample)
{
    float z0_y_coeff = filter_coefficients.z_y[0];
    float z1_y_coeff = filter_coefficients.z_y[1];
    float z2_y_coeff = filter_coefficients.z_y[2];

    float z_x_coeff = filter_coefficients.z_x;

    float x = 0;
    if (filter_type == LP)
    {
        x = sample + 2 * delay_x[0] + delay_x[1];
    }
    else
    {
        x = sample - 2 * delay_x[0] + delay_x[1];
    }
    x *= z_x_coeff;

    float y = 2 * z1_y_coeff * delay_y[0] + z2_y_coeff * delay_y[1];
    float out = (x - y) / z0_y_coeff;

    std::swap(delay_x[0], delay_x[1]);
    std::swap(delay_y[0], delay_y[1]);
    delay_x[0] = sample;
    delay_y[0] = out;

    return out;
}

inline float butter_filter::process_sample_o3(float sample)
{
    float z0_y_coeff = filter_coefficients.z_y[0];
    float z1_y_coeff = filter_coefficients.z_y[1];
    float z2_y_coeff = filter_coefficients.z_y[2];
    float z3_y_coeff = filter_coefficients.z_y[3];

    float z_x_coeff = filter_coefficients.z_x;

    float x = 0;
    if (filter_type == LP)
    {
        x = sample + 3 * delay_x[0] + 3 * delay_x[1] + delay_x[2];
    }
    else
    {
        x = sample - 3 * delay_x[0] + 3 * delay_x[1] - delay_x[2];
    }

    x *= z_x_coeff;

    float y = z1_y_coeff * delay_y[0] + z2_y_coeff * delay_y[1] + z3_y_coeff * delay_y[2];

    float out = (x - y) / z0_y_coeff;

    std::swap(delay_x[2], delay_x[1]);
    std::swap(delay_x[0], delay_x[1]);

    std::swap(delay_y[2], delay_y[1]);
    std::swap(delay_y[0], delay_y[1]);

    delay_x[0] = sample;
    delay_y[0] = out;
    return out;
}