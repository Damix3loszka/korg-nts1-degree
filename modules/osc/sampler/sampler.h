#include "sound_samples.h"
#include "userosc.h"

#define KICK_MIDI_MIN 45
#define KICK_MIDI_MAX KICK_MIDI_MIN + 2

#define SNARE_MIDI_MIN KICK_MIDI_MAX + 1
#define SNARE_MIDI_MAX SNARE_MIDI_MIN + 4

#define CLAP_MIDI_MIN SNARE_MIDI_MAX + 1
#define CLAP_MIDI_MAX CLAP_MIDI_MIN + 6

#define CLOSEDHAT_MIDI_MIN CLAP_MIDI_MAX + 1
#define CLOSEDHAT_MIDI_MAX CLOSEDHAT_MIDI_MIN + 2
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
    void start(uint8_t midi_note);
    void stop();

  private:
    playback_state state;
    uint16_t *sounds_samples[4] = {kick_samples, snare_samples, clap_samples, closedhat_samples};
    int sounds_sample_count[4] = {KICK_SAMPLES_COUNT, SNARE_SAMPLES_COUNT, CLAP_SAMPLES_COUNT, CLOSEDHAT_SAMPLES_COUNT};
    uint8_t num_of_samples_to_interp;
    float cast_sample_to_float(uint16_t sample);
    SOUND midi_to_sound(uint8_t midi_note);
};
