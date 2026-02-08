FROM ubuntu:24.04

ARG USER
ARG USER_ID
ARG USER_PASS

ARG DIR=split-kb

RUN useradd -m -u $USER_ID -p $USER_PASS -d /home/$USER $USER && \
    mkdir /home/$USER/$DIR

RUN usermod -aG sudo -s /usr/bin/bash ${USER} && \
    apt update && \
    apt install -y \
        sudo git gcc make wget unzip zip \
        diffutils clang-format-18 libclang-cpp18 libelf1t64 \
        libftdi1 libhidapi-libusb0 libicu74 libllvm18 libnewlib-dev \
        libstdc++-arm-none-eabi-dev libstdc++-arm-none-eabi-newlib libusb-0.1-4 \
        libusb-1.0-0 libxml2 avrdude-doc gcc-doc libnewlib-doc avr-libc avrdude \
        binutils-arm-none-eabi binutils-avr clang-format clang-format-18 \
        dfu-programmer dfu-util gcc-arm-none-eabi gcc-avr libclang-cpp18 libelf1t64 \
        libftdi1 libhidapi-hidraw0 libhidapi-libusb0 libicu74 libllvm18 \
        libnewlib-arm-none-eabi libnewlib-dev libstdc++-arm-none-eabi-dev \
        libstdc++-arm-none-eabi-newlib libusb-0.1-4 libusb-1.0-0 libusb-dev libxml2 \
        teensy-loader-cli python3 python3-pip openssh-client && \
    apt clean && \
    rm -rf /var/lib/apt/lists/*

USER $USER

RUN python3 -m pip install --user qmk --break-system-packages && \
    echo 'PATH="$HOME/.local/bin:$PATH"' >> $HOME/.bashrc && \
    mkdir -p /home/$USER/.config/qmk && \
    touch /home/$USER/.config/qmk/qmk.ini && \
    echo [user] >> /home/$USER/.config/qmk/qmk.ini && \
    echo qmk_home = /home/$USER/split-kb/qmk_firmware >> /home/$USER/.config/qmk/qmk.ini && \
    echo overlay_dir = /home/$USER/split-kb >> /home/$USER/.config/qmk/qmk.ini

WORKDIR /home/$USER/$DIR
