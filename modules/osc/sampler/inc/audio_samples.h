#include "./sample_files/kick_samples.h"
#include "./sample_files/snare_samples.h"
#include "./sample_files/clap_samples.h"
#include "./sample_files/closedhat_samples.h"
#define AUDIO_SAMPLERATE 24000.0
#define AUDIO_COUNT 4
#define MIDI_START 45
uint16_t *audio_samples[4] = {kick_samples,snare_samples,clap_samples,closedhat_samples,};
uint16_t audio_sample_count[4] = {KICK_SAMPLES_COUNT,SNARE_SAMPLES_COUNT,CLAP_SAMPLES_COUNT,CLOSEDHAT_SAMPLES_COUNT,};
float audio_min_sample[4] = {KICK_MIN_SAMPLE,SNARE_MIN_SAMPLE,CLAP_MIN_SAMPLE,CLOSEDHAT_MIN_SAMPLE,};
float audio_attenuation_factor[4] = {KICK_ATTENUATION_FACTOR,SNARE_ATTENUATION_FACTOR,CLAP_ATTENUATION_FACTOR,CLOSEDHAT_ATTENUATION_FACTOR,};
enum SOUND 
{
KICK,
SNARE,
CLAP,
CLOSEDHAT,
NONE,
};