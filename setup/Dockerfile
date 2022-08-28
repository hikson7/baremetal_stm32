# Development image for building Arm devices
# Last visited: 06 Aug 2022

# FROM arm64v8/ubuntu:focal
FROM --platform=linux/x86_64 ubuntu:focal
LABEL Description="Development image for building Arm devices"

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y \
        wget \
        xz-utils \
        vim \
        minicom

# RUN apt-get install -y \
#     gdb-multiarch \
#     openocd \
#     libncursesw5

# RUN apt-get install -y \
#     gdb-multiarch \
#     libncursesw5 \
#     nodejs \
#     npm

# Dependency for arm-none-eabi-gdb
# Found from dpkg -L libpython3.8
# RUN cd /usr/lib/x86_64-linux-gnu/ && \
#     ln -s libpython3.8.so.1.0 libpython3.6m.so.1.0

# Find appropriate download link from ARM: https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/downloads
ARG ARM_GNU_DOWNLOAD_LINK=https://developer.arm.com/-/media/Files/downloads/gnu/11.2-2022.02/binrel/gcc-arm-11.2-2022.02-x86_64-arm-none-eabi.tar.xz

RUN wget -qO'-' $ARM_GNU_DOWNLOAD_LINK | tar -xJ
# RUN wget --quiet --output-document='-' $ARM_GNU_DOWNLOAD_LINK | tar --extract --xz

# RUN wget -qO'-' $ARM_GNU_DOWNLOAD_LINK | tar -xJf '-'
# RUN wget --quiet --output-document='-' $ARM_GNU_DOWNLOAD_LINK | tar --extract --xz --file='-'

ARG MY_WORKDIR
WORKDIR ${MY_WORKDIR}

ENV PATH "/gcc-arm-11.2-2022.02-x86_64-arm-none-eabi/bin:$PATH"
