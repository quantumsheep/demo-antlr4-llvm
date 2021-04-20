#!/bin/bash

./compile-grammar.sh

mkdir -p build
cd build
cmake ..
cmake --build .
