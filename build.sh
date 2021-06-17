#!/usr/bin/env bash

mkdir -p build
cd build || exit 1
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug
cmake --build .