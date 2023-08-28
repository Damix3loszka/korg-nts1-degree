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

struct playback_state
{
    uint8_t current_midi_note;
    SOUND current_sound;
    uint16_t current_sample_index;
    uint8_t interp_sample_num;
    bool play;
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
            play : false
        };
        num_of_samples_to_interp = k_samplerate / 24000;
    };
    float next_sample();
    inline void start(uint8_t midi_note);
    inline void stop();

  private:
    playback_state state;
    uint16_t *sounds_samples[4] = {kick_samples, snare_samples, clap_samples, closedhat_samples};
    int sounds_sample_count[4] = {KICK_SAMPLES_COUNT, SNARE_SAMPLES_COUNT, CLAP_SAMPLES_COUNT, CLOSEDHAT_SAMPLES_COUNT};
    uint8_t num_of_samples_to_interp;
    uint8_t midi_keyboard_section_start[4] = {45, 48, 53, 60};
    float cast_sample_to_float(uint16_t sample);
    SOUND midi_to_sound(uint8_t midi_note);
};

float sampler::cast_sample_to_float(uint16_t sample)
{
    return ((float)sample / UINT16_MAX + (state.current_sound == KICK ? KICK_MIN_SAMPLE : SNARE_MIN_SAMPLE));
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

inline void sampler::start(uint8_t midi_note)
{
    state.current_midi_note = midi_note;
    state.current_sound = midi_to_sound(state.current_midi_note);
    if (state.current_sound)
        state.play = false;
}

inline float sampler::next_sample()
{
    float sample_return = 0.f;

    if (state.play)
    {
        uint16_t max_sample_index = 0;
        switch (state.current_sound)
        {
        case KICK:
            max_sample_index = KICK_SAMPLES_COUNT - 1;
            break;
        case SNARE:
            max_sample_index = SNARE_SAMPLES_COUNT - 1;
            break;
        case CLAP:
            max_sample_index = CLAP_SAMPLES_COUNT - 1;
            break;
        case CLOSED_HAT:
            max_sample_index = CLOSEDHAT_SAMPLES_COUNT - 1;
            break;
        };

        uint16_t raw_sample_1 = sounds_samples[state.current_sound][state.current_sample_index];
        uint16_t raw_sample_2 = sounds_samples[state.current_sound][state.current_sample_index + 1];

        float sample_1_f = cast_sample_to_float(raw_sample_1);
        float sample_2_f = cast_sample_to_float(raw_sample_2);
        sample_return = linintf(state.interp_sample_num / num_of_samples_to_interp, sample_1_f, sample_2_f);
        ++state.interp_sample_num;
        if (state.interp_sample_num == num_of_samples_to_interp)
        {
            ++state.current_sample_index;
            state.interp_sample_num %= num_of_samples_to_interp;
        }
        if (state.current_sample_index >= max_sample_index)
            state.play = false;
    }

    return sample_return;
}
inline void sampler::stop()
{
    state.play = true;
    state.current_sample_index = 0;
}