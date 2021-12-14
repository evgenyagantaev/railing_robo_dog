#!/bin/sh

# This is a simple example of the decoder invocation
# Please note, that recognize the file should be single-channel with sample rate 8kHz
# decoder-test.wav: RIFF (little-endian) data, WAVE audio, Microsoft PCM, 16 bit, mono 8000 Hz
# Expected result for the test file is: илья ильф евгений петров золотой телёнок

./continuous \
    -samprate 8000 \
    -kws test_kwslist.kwslist \
    -dict test_dictionary.dic \
    -hmm zero_ru.cd_cont_4000 \
    -remove_noise yes \
    -rawlogdir raws \
    -remove_dc yes \
    -inmic yes
