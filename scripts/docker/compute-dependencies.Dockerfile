FROM quay.io/centos/centos:stream9

RUN dnf -y update && \
    dnf -y install epel-release && \
    dnf install -y --nogpgcheck https://mirrors.rpmfusion.org/free/el/rpmfusion-free-release-9.noarch.rpm && \
    dnf -y install \
    git \
    clang \
    gcc-c++ \
    make \
    cmake \
    ccache \
    ffmpeg-free-devel --skip-broken \
    libavformat-free-devel \
    libavcodec-free-devel \
    libavutil-free-devel \
    libswscale-free-devel \
    libswresample-free-devel \
    && dnf clean all

# FFMPEG compilation from source
RUN dnf config-manager --set-enabled crb
RUN dnf install -y \
  autoconf automake bzip2 bzip2-devel cmake freetype-devel gcc gcc-c++ \
  git libtool make pkgconfig zlib-devel nasm yasm \
  && dnf clean all

WORKDIR /tmp
RUN git clone https://git.ffmpeg.org/ffmpeg.git ffmpeg
WORKDIR /tmp/ffmpeg
RUN git fetch && git checkout n8.0
RUN ./configure \
  --prefix=/opt/ffmpeg-static \
  --pkg-config-flags="--static" \
  --extra-cflags="-I/opt/ffmpeg-static/include" \
  --extra-ldflags="-L/opt/ffmpeg-static/lib" \
  --extra-libs="-lpthread -lm" \
  --enable-static \
  --disable-shared \
  --disable-doc \
  --disable-programs \
  --disable-debug \
  --enable-avformat \
  --enable-avcodec \
  --enable-avutil \
  --enable-swscale \
  --enable-swresample \
  && make -j$(nproc) && make install

