project(video-converter-compute LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(/opt/ffmpeg-static/include)
link_directories(/opt/ffmpeg-static/lib)

add_executable(video-converter-compute src/main.cpp)

target_link_libraries(video-converter-compute
  /opt/ffmpeg-static/lib/libavformat.a
  /opt/ffmpeg-static/lib/libavcodec.a
  /opt/ffmpeg-static/lib/libavutil.a
  /opt/ffmpeg-static/lib/libswscale.a
  /opt/ffmpeg-static/lib/libswresample.a
  # External dependencies required by FFmpeg
  bz2       # For libavformat (Matroska, etc.)
  z         # Compression
  m         # Math
  pthread   # Threading
  dl        # Dynamic loading
)

