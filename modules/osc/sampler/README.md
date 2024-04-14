# Sampler

Oscillator module which allows to import up to four .wav samples into the synthesizer. 

Supplied package contains drum samples from [MusicRadar](https://www.musicradar.com/news/sampleradar-494-free-essential-drum-kit-samples)

### Requirements
[Python](https://www.python.org/) with [Librosa]([li](https://librosa.org/doc/latest/index.html)) were used to process sample files. [LogueSDK](https://github.com/korginc/logue-sdk/blob/master/platform/nutekt-digital/README.md) for building a .ntkdigunit package.

### Usage
To fit user samples in the memory bank of a module they first need to be reduced in size. This means downsampling, monophonization and bit depth limit (16bit). Samples don't need to match 48kHz of synthesizer or bit depth limit - they will be resampled and bit depth will be reduced if necessary.

#### Configuration
First step is the configuration which is done by editing *config.json* file in *utility* folder.

File structure:
| Variable            | Function                                                                                            |     |
| ------------------- | --------------------------------------------------------------------------------------------------- | --- |
| downsampling_factor | Factor by which sampling rate is reduced (e.g. choosing3 leads to downsampling from 48kHz to 16kHz) |
| midi_start          | MIDI value of the first key on the keyboard                                                         |
| audiofile_paths     | Paths of files to convert                                                                           |
| audiofile_names     | Names of used sounds (e.g. Snare, Kick)                                                             |
| output_path         | Path where converted samples are stored (better be left as is)                                      |

To find the MIDI value of the first key use MIDIfind.ntkdigunit. After loading press the first key on the keyboard and turn A knob until you hear white noise. The value on the screen is your midi_start value.

#### Conversion
Simply run *convert.py* in *utility* folder.

#### Building a package
Follow instructions [here](https://github.com/korginc/logue-sdk/blob/master/platform/nutekt-digital/README.md#building-the-demo-oscillator-waves) to build .ntkdigunit pakcage.




