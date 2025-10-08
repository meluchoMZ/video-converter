cmake_minimum_required(VERSION 3.26)
project(video-converter-compute LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

cmake_policy(SET CMP0135 NEW)

include(FetchContent)
FetchContent_Declare(
  googletest # v1.17.0
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)
FetchContent_MakeAvailable(googletest)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

include_directories(/opt/ffmpeg-static/include)
link_directories(/opt/ffmpeg-static/lib)

option(BUILD_TESTS "Enable test builds" OFF)
if (BUILD_TESTS)
	enable_testing()
	include(CTest)
endif()

add_subdirectory(src)

add_executable(video-converter-compute main.cpp)

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
  # Project submodules linking
  video-converter-libs       # Logging
)

