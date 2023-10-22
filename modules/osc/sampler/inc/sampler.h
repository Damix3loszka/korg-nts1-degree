#include "sound_samples.h"
#include "userosc.h"
#define NUM_OF_SOUNDS 4

enum SOUND
{
    KICK = 0,
    SNARE = 1,
    CLAP = 2,
    CLOSED_HAT = 3,
    NONE = 4
};
float p4_o2_interpolation(float x, float y_1, float y0, float y1, float y2)
{
    float z = x - 1 / 2.0;
    float even1 = y1 + y0, odd1 = y1 - y0;
    float even2 = y2 + y_1, odd2 = y2 - y_1;
    float c0 = even1 * 0.42334633257225274 + even2 * 0.07668732202139628;
    float c1 = odd1 * 0.26126047291143606 + odd2 * 0.24778879018226652;
    float c2 = even1 * -0.213439787561776841 + even2 * 0.21303593243799016;
    return (c2 * z + c1) * z + c0;
}
struct playback_state
{
    uint8_t current_midi_note;
    SOUND current_sound;
    uint16_t current_sample_index;
    uint8_t interp_sample_num;
    bool start;
};

class sampler
{
  public:
    sampler()
    {
        state = {
            current_midi_note : 0,
            current_sound : NONE,
            current_sample_index : 0,
            interp_sample_num : 0,
            start : false
        };
        sampling_ratio = k_samplerate / 24000;
    };
    float next_sample();
    void noteon();
    void noteoff(uint8_t midi_note);

  private:
    playback_state state;
    uint16_t *sounds_samples[4] = {kick_samples, snare_samples, clap_samples, closedhat_samples};
    uint16_t sounds_sample_count[4] = {KICK_SAMPLES_COUNT, SNARE_SAMPLES_COUNT, CLAP_SAMPLES_COUNT,
                                       CLOSEDHAT_SAMPLES_COUNT};
    float sounds_min_sample[4] = {KICK_MIN_SAMPLE, SNARE_MIN_SAMPLE, CLAP_MIN_SAMPLE, CLOSEDHAT_MIN_SAMPLE};
    uint8_t sampling_ratio;
    uint8_t midi_keyboard_section_start[4] = {45, 48, 53, 60};
    float cast_sample_to_float(uint16_t sample);
    SOUND midi_to_sound(uint8_t midi_note);
};

float sampler::cast_sample_to_float(uint16_t sample)
{
    return ((float)sample / UINT16_MAX + sounds_min_sample[state.current_sound]);
}

inline SOUND sampler::midi_to_sound(uint8_t midi_note)
{
    SOUND sound = NONE;
    uint8_t i = NUM_OF_SOUNDS - 1;
    for (i; i >= 0; --i)
    {
        if (midi_note >= midi_keyboard_section_start[i])
        {
            break;
        }
    }

    if ((midi_note - midi_keyboard_section_start[i]) % 2 == 0)
    {
        sound = static_cast<SOUND>(i);
    }
    return sound;
}

inline float sampler::next_sample()
{
    float sample_return = 0.f;

    if (state.start)
    {
        uint16_t sample_index = state.current_sample_index;
        SOUND sound = state.current_sound;
        uint16_t max_sample_number = sounds_sample_count[sound];
        uint16_t max_sample_index = max_sample_number - 1;

        if (state.interp_sample_num == 0)
            sample_return = cast_sample_to_float(sounds_samples[sound][sample_index]);
        else
        {
            float samples_f[4] = {};
            for (uint8_t i = 0; i < 4; ++i)
            {
                int temp_index = sample_index - 1 + i;
                uint16_t index = (max_sample_number + temp_index) % (max_sample_number);

                samples_f[i] = cast_sample_to_float(sounds_samples[sound][index]);
            };
            sample_return = p4_o2_interpolation(state.interp_sample_num / sampling_ratio, samples_f[0], samples_f[1],
                                                samples_f[2], samples_f[3]);

            ++state.current_sample_index;
        }

        state.interp_sample_num = (++state.interp_sample_num) % sampling_ratio;
        if (state.current_sample_index > max_sample_index)
            state.start = false;
    }

    return sample_return;
}
inline void sampler::noteon()
{
    state.start = false;
}
inline void sampler::noteoff(uint8_t midi_note)
{
    state.current_midi_note = midi_note;
    state.current_sound = midi_to_sound(state.current_midi_note);
    if (state.current_sound != NONE)
        state.start = true;
    state.current_sample_index = 0;
}