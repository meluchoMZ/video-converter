FROM compute-release:centos9 as release-build
FROM quay.io/centos/centos:stream9

WORKDIR /app

COPY --from=release-build /workspace/video-converter/build/video-converter-compute /app/video-converter-compute

CMD ["./video-converter-compute"]

