#include "usermodfx.h"
#include <algorithm>
#include <math.h>
#define PASSBAND_GAIN -3.f  // dB
#define STOPBAND_GAIN -24.f // dB
#define MIN_STOPBAND_PASSBAND_RATIO 1.128f
#define MAX_STOPBAND_FREQUENCY 10000 // Hz
#define MAX_PASSBAND_FREQUENCY 8865  // Hz, 10000/1.12
#define k_samplerate_recipf (2.08333333333333e-005f)
#define k_samplerate 48000
float butterworth_coeffiients[10][10] = {
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1.1412, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {2, 2, 1, 0, 0, 0, 0, 0, 0, 0},
    {2.6131, 3.4142, 2.6131, 1, 0, 0, 0, 0, 0, 0},
    {3.2361, 5.2361, 5.2361, 3.2361, 1, 0, 0, 0, 0, 0},
    {3.8637, 7.4641, 9.1416, 7.4641, 3.8637, 1, 0, 0, 0, 0},
    {4.4940, 10.0987, 14.5918, 14.5918, 10.0987, 4.4940, 1, 0, 0, 0},
    {5.1258, 13.1371, 21.8462, 25.6884, 21.8462, 13.1371, 5.1258, 1, 0, 0},
    {5.7588, 16.5817, 31.1634, 41.9864, 41.9864, 31.1634, 16.5817, 5.7588, 1, 0},
    {6.3925, 20.4317, 42.8021, 64.8824, 74.2334, 64.8824, 42.8021, 20.4317, 6.3925, 1},
};
class butter_filter
{
  public:
    float process_sample(float sample);
    void set_cutoff_freq(float frac);

  private:
    float passband_freq;
    float delay_x[2] = {0, 0};
    float delay_y[2] = {0, 0};
    float cutoff_frequency = 0.f;
    float analog_frequency = 0.f;
};

// y[n] + 2y [n - 1] + y[n - 2] = (2 + sqrt(2))(x[n] + 2 - fsqrt(2) x[n - 2]);
inline void butter_filter::set_cutoff_freq(float frac)
{
    cutoff_frequency = 20000.f * frac;
    analog_frequency = fasttanf(cutoff_frequency * k_samplerate_recipf / 2);
}

inline float butter_filter::process_sample(float sample)
{
    float wa = analog_frequency;
    float wa2 = fastpowf(wa, 2);
    float common_denominator = 1.f + wa * M_SQRT2 + wa2;
    float z_2_coefficient = common_denominator - wa * M_SQRT2 * 2.f;

    float out = (wa2 / common_denominator) * (sample + 2.f * delay_x[0] + delay_x[1]) -
                ((2.f * (wa2 - 1) * delay_y[0] + z_2_coefficient * delay_y[1]) / common_denominator);

    std::swap(delay_x[0], delay_x[1]);
    std::swap(delay_y[0], delay_y[1]);
    delay_x[0] = sample;
    delay_y[0] = out;

    return out;
}
