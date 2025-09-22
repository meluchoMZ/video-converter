#include <iostream>
extern "C" {
#include <libavformat/avformat.h>
}

int main() {
    std::cout << "VIDEO CONVERTER COMPUTE NODE" << std::endl;
    
    std::cout << "Initializing FFMPEG LIBAVFORMAT protocols..." << std::endl;

    // Initialize libavformat and register all the muxers, demuxers and protocols
    avformat_network_init();

    // Create a format context
    AVFormatContext* fmt_ctx = avformat_alloc_context();
    if (!fmt_ctx) {
        std::cerr << "Failed to allocate format context." << std::endl;
        return 1;
    }

    std::cout << "FFmpeg format context initialized successfully." << std::endl;

    // Clean up
    avformat_free_context(fmt_ctx);
    avformat_network_deinit();

    return 0;
}

