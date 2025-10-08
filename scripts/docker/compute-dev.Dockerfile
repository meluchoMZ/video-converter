ARG BASE_IMAGE=compute-dependency:centos9
FROM ${BASE_IMAGE} as dependency-image

ARG BUILD_TYPE
ARG BUILD_TESTS
ENV CC=clang
ENV CXX=clang++
ENV PATH="/usr/lib64/ccache:${PATH}"

WORKDIR /workspace/video-converter
COPY compute/ /workspace/video-converter

RUN mkdir -p build && cd build && \
    cmake -DCMAKE_BUILD_TYPE=${BUILD_TYPE} -DBUILD_TESTS=${BUILD_TESTS} .. && \
    make

