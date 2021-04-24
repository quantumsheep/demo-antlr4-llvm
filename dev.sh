#!/bin/bash

set -xe

docker build . -t demo-antlr4-llvm-dev

docker run --rm -it \
--mount type=bind,source="$(pwd)"/,target=/usr/src/app/ \
demo-antlr4-llvm-dev
