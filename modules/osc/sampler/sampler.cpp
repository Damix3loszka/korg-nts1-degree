

float sampler::cast_sample_to_float(uint16_t sample, SOUND sound)
{
    return (float)(sample / UINT16_MAX - (sound == KICK ? KICK_MIN_SAMPLE : SNARE_MIN_SAMPLE));
}

SOUND sampler::midi_to_sound(uint8_t midi_note)
{
    SOUND sound;
    if (KICK_MIDI_MIN <= midi_note <= KICK_MIDI_MAX)
    {
        sound = KICK;
    }
    else if (SNARE_MIDI_MIN <= midi_note <= SNARE_MIDI_MAX)
    {
        sound = SNARE;
    }
    return sound;
}

void sampler::reset(uint8_t midi_note)
{
    current_midi_note = midi_note;
    current_sound = midi_to_sound(current_midi_note);
    sample_counter = 0;
    play = true;
}

float sampler::next_sample()
{
    float sample_return = 0.f;

    if (play)
    {
        uint16_t max_sample_index = current_sound == KICK ? KICK_SAMPLES_COUNT : SNARE_SAMPLES_COUNT - 1;
        uint16_t raw_sample = current_sound == KICK ? kick_samples[sample_counter] : sample_counter;

        float sample_return = cast_sample_to_float(raw_sample, current_sound);

        if (sample_counter > max_sample_index)
            play = false;
        ++sample_counter;
    }

    return sample_return;
}