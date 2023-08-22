#include "sound_samples.h"
#include "userosc.h"
#define KICK_MIDI_MIN 45
#define KICK_MIDI_MAX KICK_MIDI_MIN + 2

#define SNARE_MIDI_MIN 60
#define SNARE_MIDI_MAX SNARE_MIDI_MIN + 2

enum SOUND
{
    KICK = 0,
    SNARE = 1,
    CLAP = 2,
    CLOSED_HAT = 3,
    NONE = 4
};

typedef struct playback_state
{
    uint8_t current_midi_note;
    SOUND current_sound;
    uint32_t current_sample_index;
    uint8_t interp_sample_num;
    bool play;
};

class sampler
{
  public:
    sampler()
    {
        sounds_sample_count[0] = KICK_SAMPLES_COUNT;
        sounds_sample_count[1] = SNARE_SAMPLES_COUNT;
        state = {
            current_midi_note : 0,
            current_sound : NONE,
            current_sample_index : 0,
            interp_sample_num : 0,
            play : false
        };
        num_of_samples_to_interp = k_samplerate / 12000;
    };
    float next_sample();
    void start(uint8_t midi_note);
    void stop();

  private:
    playback_state state;
    uint16_t *sounds_samples[4] = {
        kick_samples,
        snare_samples,
        clap_samples,
    };
    int sounds_sample_count[2];
    uint8_t num_of_samples_to_interp;
    float cast_sample_to_float(uint16_t sample);
    SOUND midi_to_sound(uint8_t midi_note);
};
