#!/bin/python3
import numpy as np
import librosa
import glob
from os import path
import json

with open("./config.json") as file:
    config = json.load(file)


audiofile_paths = [path.abspath(p) for p in config["audiofile_paths"]]
audiofiles_samplerate = config["audiofiles_samplerate"]
downsampling_factor = config["downsampling_factor"]
audiofile_names = config["audiofile_names"]
output_path = path.abspath(config["output_path"])


with open(f"{output_path}/../audio_samples.h", "w") as includefile:
    for i, filepath in enumerate(audiofile_paths):
        samples, sample_rate = librosa.load(
            filepath, sr=audiofiles_samplerate / downsampling_factor, mono=True
        )
        m = samples.min()
        uint_max = np.iinfo(np.uint16).max
        samples = (samples - m) * uint_max
        samples = samples.astype(np.uint16)

        converted_audio_filename = f"{audiofile_names[i].lower()}_samples.h"

        with open(f"{output_path}/{converted_audio_filename}", "w") as samplefile:
            samplefile.write('#include "stdint.h"\n')
            samplefile.write(
                f"#define {audiofile_names[i]}_SAMPLES_COUNT {len(samples)}\n"
            )
            samplefile.write(f"#define {audiofile_names[i]}_MIN_SAMPLE {m}\n")
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
        f"#define AUDIO_SAMPLERATE {audiofiles_samplerate/downsampling_factor}\n"
    )
    includefile.write(f"#define AUDIO_COUNT {len(audiofile_paths)}\n")
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
