#include "audio_samples.h"
#include "userosc.h"
#define MIDI_START 45
enum SOUND
{
    KICK = 0,
    SNARE = 1,
    CLAP = 2,
    CLOSED_HAT = 3,
    NONE = 4
};

struct playback_state
{
    SOUND current_sound;
    uint16_t current_sample_index;
    uint8_t interpolation_counter;
    bool start;
};

class sampler
{
  public:
    sampler()
    {
        state = {current_sound : NONE, current_sample_index : 0, interpolation_counter : 0, start : false};
        sampling_ratio = k_samplerate / AUDIO_SAMPLERATE;
    };
    float next_sample();
    void noteon();
    void noteoff(uint8_t midi_note);

  private:
    playback_state state;
    uint16_t **sounds_samples = audio_samples;
    uint16_t *sounds_sample_count = audio_sample_count;
    float *sounds_min_sample = audio_min_sample;
    uint8_t sampling_ratio;
    uint8_t midi_keyboard_section_start[4] = {MIDI_START, MIDI_START + 3, MIDI_START + 8,
                                              MIDI_START + 15}; // 45,48,53,60
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
    uint8_t i = AUDIO_COUNT - 1;
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

        if (state.interpolation_counter == 0)
            sample_return = cast_sample_to_float(sounds_samples[sound][sample_index]);
        else
        {
            float sample_1 = cast_sample_to_float(sounds_samples[sound][sample_index]);
            float sample_2 = cast_sample_to_float(sounds_samples[sound][sample_index + 1]);
            sample_return = linintf(state.interpolation_counter / sampling_ratio, sample_1, sample_2);
        }

        state.interpolation_counter = (++state.interpolation_counter) % sampling_ratio;
        if (state.interpolation_counter == 0)
        {
            ++state.current_sample_index;
        }
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
    state.current_sound = midi_to_sound(midi_note);
    if (state.current_sound != NONE)
        state.start = true;
    state.current_sample_index = 0;
}