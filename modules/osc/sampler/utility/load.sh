#!/bin/bash
logue-cli load -v -i 1 -o 1 -s 0 -u $1 -d > load.log
tail -n1 load.log| sed 's/,//g' | sed 's/}//g' | sed 's/{//g' | sed 's/>//g' | sed 's/^ *//g' > load.sysex
amidi -p hw:1,0,0 -S `cat load.sysex`