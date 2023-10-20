#!/bin/python3
import numpy as np
import librosa
import glob
from pathlib import PurePosixPath

soundfiles = sorted([PurePosixPath(file) for file in glob.glob("../audiofiles/*")])
divider = 2
SAMPLERATE = 48000
drum_element = ["CLAP", "CLOSEDHAT", "KICK", "SNARE"]

for i, file in enumerate(soundfiles):
    samples, sample_rate = librosa.load(file, sr=SAMPLERATE / divider, mono=True)
    m = samples.min()
    uint_max = np.iinfo(np.uint16).max
    samples = (samples - m) * uint_max
    samples = samples.astype(np.uint16)

    with open(f"./sample_txt/{drum_element[i].lower()}_samples.h", "w") as file:
        file.write('#include "userosc.h"\n')
        file.write(f"#define {drum_element[i]}_SAMPLERATE {SAMPLERATE/divider}\n")
        file.write(f"#define {drum_element[i]}_SAMPLES_COUNT {len(samples)}\n")
        file.write(f"#define {drum_element[i]}_MIN_SAMPLE {m}\n")
        file.write(
            f"uint16_t {drum_element[i].lower()}_samples[{drum_element[i]}_SAMPLES_COUNT] = "
            + "{\n"
        )
        for sample in samples:
            file.write(f"{sample}, ")
        file.write("};")
