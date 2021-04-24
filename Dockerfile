FROM ubuntu:bionic

RUN set -xe && \
    apt-get update && \
    apt-get install -y --no-install-recommends \
    ca-certificates \
    lsb-release \
    wget \
    software-properties-common \
    gpg-agent \
    libedit-dev \
    uuid-dev \
    zlib1g-dev \
    openjdk-8-jre-headless \
    build-essential \
    pkg-config \
    cmake \
    git

RUN set -xe && \
    wget https://apt.llvm.org/llvm.sh && \
    chmod +x llvm.sh && \
    ./llvm.sh 11

RUN set -xe && \
    git config --global user.email "johndoe@example.com" && \
    git config --global user.name "John Doe"

WORKDIR /usr/src/app

COPY . .

CMD bash
