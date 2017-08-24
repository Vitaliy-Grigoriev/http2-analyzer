#!/usr/bin/env bash

mkdir check && cd check
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -j4 ..
cppcheck -q --language=c++ --template=vs -I/usr/include/ -I/usr/include/c++/6 -I../include/analyzer/ --std=c++11 --enable=all --project=compile_commands.json
cd .. && rm -rf check
