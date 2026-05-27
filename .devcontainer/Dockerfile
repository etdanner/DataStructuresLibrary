FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
    gcc \
    g++ \
    gdb \
    make \
    cmake \
    clang \
    clang-format \
    clangd \
    valgrind \
    libasan6 \
    strace \
    ltrace \
    bear \
    git \
    && rm -rf /var/lib/apt/lists/*

ARG USERNAME=dev
RUN useradd -ms /bin/bash $USERNAME
USER $USERNAME
WORKDIR /home/$USERNAME