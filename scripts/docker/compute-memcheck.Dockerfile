FROM compute-debug:centos9

RUN dnf install -y valgrind
CMD ["valgrind","--leak-check=yes", "./build/video-converter-compute"]
