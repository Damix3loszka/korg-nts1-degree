/**
    Guillaume Elias 2020. Use this file at your own peril.
    This project is under BSD3 license. See LICENSE file.
*/
// #include "sampler.h"
//#include "sampler.h"

#include "sampler.h"
#include "userosc.h"

sampler samp = sampler();

void OSC_INIT(uint32_t platform, uint32_t api)
{
}

void OSC_CYCLE(const user_osc_param_t *const params, int32_t *yn, const uint32_t frames)
{

    q31_t *__restrict y = (q31_t *)yn;

    const q31_t *y_e = y + frames;

    for (; y != y_e;)
    {

        const float sig = samp.next_sample();

        *(y++) = f32_to_q31(sig);
    }
}
void OSC_NOTEON(const user_osc_param_t *const params)
{
    samp.start((params->pitch) >> 8);
}

void OSC_NOTEOFF(const user_osc_param_t *const params)
{
    (void)params;
    samp.stop();
}

void OSC_PARAM(uint16_t index, uint16_t value)
{
    switch (index)
    {
    case k_user_osc_param_id1:
        break;
    case k_user_osc_param_shape:
        break;
    case k_user_osc_param_shiftshape:
    default:
        break;
    }
}
float sampler::cast_sample_to_float(uint16_t sample)
{
    return ((float)sample / UINT16_MAX + (state.current_sound == KICK ? KICK_MIN_SAMPLE : SNARE_MIN_SAMPLE));
}

SOUND sampler::midi_to_sound(uint8_t midi_note)
{
    SOUND sound = NONE;
    if (KICK_MIDI_MIN <= midi_note && midi_note <= KICK_MIDI_MAX)
    {
        sound = KICK;
    }
    else if (SNARE_MIDI_MIN <= midi_note && midi_note <= SNARE_MIDI_MAX)
    {
        sound = SNARE;
    }
    if (CLAP_MIDI_MIN <= midi_note && midi_note <= CLAP_MIDI_MAX)
    {
        sound = CLAP;
    }
    else if (CLOSEDHAT_MIDI_MIN <= midi_note && midi_note <= CLOSEDHAT_MIDI_MAX)
    {
        sound = CLOSED_HAT;
    }

    return sound;
}

void sampler::start(uint8_t midi_note)
{
    state.current_midi_note = midi_note;
    state.current_sound = midi_to_sound(state.current_midi_note);
    if (state.current_sound)
        state.play = false;
}

float sampler::next_sample()
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
void sampler::stop()
{
    state.play = true;
    state.current_sample_index = 0;
}