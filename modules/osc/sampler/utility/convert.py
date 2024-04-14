#!/bin/python3
import numpy as np
import librosa
from os import path
import json

with open("./config.json") as file:
    config = json.load(file)


audiofile_paths = [path.abspath(p) for p in config["audiofile_paths"]]
downsampling_factor = config["downsampling_factor"]
audiofile_names = config["audiofile_names"]
output_path = path.abspath(config["output_path"])
midi_start = config["midi_start"]
max_size = 31 * 1024
full_size = 0

with open(f"{output_path}/../audio_samples.h", "w") as includefile:
    for i, filepath in enumerate(audiofile_paths):
        samples, sample_rate = librosa.load(
            filepath, sr=48000 / downsampling_factor, mono=True
        )
        m = samples.min()
        attenuation_factor = 0.5 / abs(m) if abs(m) > 0.5 else 1
        uint_max = np.iinfo(np.uint16).max
        samples = (samples - m) * attenuation_factor * uint_max
        samples = samples.astype(np.uint16)

        full_size += len(samples) * 2

        converted_audio_filename = f"{audiofile_names[i].lower()}_samples.h"

        with open(f"{output_path}/{converted_audio_filename}", "w") as samplefile:
            samplefile.write('#include "stdint.h"\n')
            samplefile.write(
                f"#define {audiofile_names[i]}_SAMPLES_COUNT {len(samples)}\n"
            )
            samplefile.write(f"#define {audiofile_names[i]}_MIN_SAMPLE {m}\n")
            samplefile.write(
                f"#define {audiofile_names[i]}_ATTENUATION_FACTOR {attenuation_factor}\n"
            )
            samplefile.write(
                f"uint16_t {audiofile_names[i].lower()}_samples[{audiofile_names[i]}_SAMPLES_COUNT] = "
                + "{\n"
            )
            for sample in samples:
                samplefile.write(f"{sample}, ")
            samplefile.write("};")
        includefile.write(
            f'#include "./{path.basename(output_path)}/{converted_audio_filename}"\n'
        )
    includefile.write(
        f"#define AUDIO_SAMPLERATE {48000/downsampling_factor}\n"
    )
    includefile.write(f"#define AUDIO_COUNT {len(audiofile_paths)}\n")
    includefile.write(f"#define MIDI_START {midi_start}\n")
    includefile.write("uint16_t *audio_samples[4] = {")
    for name in audiofile_names:
        includefile.write(f"{name.lower()}_samples,")
    includefile.write("};\n")

    includefile.write("uint16_t audio_sample_count[4] = {")
    for name in audiofile_names:
        includefile.write(f"{name}_SAMPLES_COUNT,")
    includefile.write("};\n")

    includefile.write("float audio_min_sample[4] = {")
    for name in audiofile_names:
        includefile.write(f"{name}_MIN_SAMPLE,")
    includefile.write("};\n")

    includefile.write("float audio_attenuation_factor[4] = {")
    for name in audiofile_names:
        includefile.write(f"{name}_ATTENUATION_FACTOR,")
    includefile.write("};\n")

    includefile.write("enum SOUND \n{\n")
    for i, audio_name in enumerate(audiofile_names):
        includefile.write(f"{audio_name.upper()},\n")

    includefile.write(f"NONE,\n")
    includefile.write("};")

    print(
        f"Size: {full_size}\nMax size:{max_size}\nFits: {'YES' if full_size<max_size else 'NO'}"
    )
