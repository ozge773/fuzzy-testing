FROM ubuntu:22.04

RUN apt-get update
RUN apt-get install -y \
    build-essential \
    python3-dev \
    automake \
    cmake \
    make \
    git \
    flex \
    bison \
    libglib2.0-dev \
    libpixman-1-dev \
    python3-setuptools \
    cargo \
    libgtk-3-dev \
    lld-14 \
    llvm-14 \
    llvm-14-dev \
    clang-14 \
    nano

RUN apt-get install -y \
    gcc-$(gcc --version | head -n1 | sed 's/\..*//' | sed 's/.* //')-plugin-dev 
RUN apt-get install -y \
    libstdc++-$(gcc --version | head -n1 | sed 's/\..*//' | sed 's/.* //')-dev 

RUN apt-get install -y \
    ninja-build \
    gdb \
    cpio \
    libcapstone-dev \
    wget \
    curl \
    python3-pip

WORKDIR /tmp
RUN git clone https://github.com/AFLplusplus/AFLplusplus
WORKDIR /tmp/AFLplusplus
RUN make distrib
RUN make install

WORKDIR /tmp
RUN rm -rf /tmp/AFLplusplus

WORKDIR /
RUN echo "ulimit -c unlimited" >> /etc/bash.bashrc


# Keep container running
CMD ["tail", "-f", "/dev/null"]
