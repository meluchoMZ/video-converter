#include <iostream>
extern "C" {
#include <libavformat/avformat.h>
#include <libavutil/avutil.h>
}

#include "src/log/ModuleLogger.h"

int main() {
	compute::log::ModuleLogger logger = compute::log::ModuleLogger("main");
	logger.info("Test logger");

	AVDictionary* options = nullptr;
	av_dict_set(&options, "video_size", "640x480", 0);
	AVFormatContext* inputFileContext = nullptr;
	if (avformat_open_input(&inputFileContext, "./test.mov", nullptr, &options) != 0) {
		std::cout << "Cannot open the file './test.mov'" << std::endl;
		return 1;
	}
	std::cout << "Opened file with format " << inputFileContext->iformat->name << std::endl;
	std::cout << "Opened file with format " << inputFileContext->iformat->long_name << std::endl;
	// retrieve stream information
	if (avformat_find_stream_info(inputFileContext, nullptr) != 0) {
		std::cout << "Cannot find stream info" << std::endl;
		return 1;
	}
	AVFormatContext* outputFileContext = nullptr;
	avformat_alloc_output_context2(&outputFileContext, nullptr, "mov", "output.mov");
	for (unsigned int i = 0; i < inputFileContext->nb_streams; i++) {
		AVStream* inputStream = inputFileContext->streams[i];
		AVStream* outputStream = avformat_new_stream(outputFileContext, nullptr);
		avcodec_parameters_copy(outputStream->codecpar, inputStream->codecpar);
		outputStream->codecpar->codec_tag = 0;
	}
	avio_open(&outputFileContext->pb, "output.mov", AVIO_FLAG_WRITE);
	int ret = avformat_write_header(outputFileContext, nullptr);
	if (ret != 0) {
		std::cout << "Error writing header to output stream" << std::endl;
	}

	AVPacket pkt;
	while (av_read_frame(inputFileContext, &pkt) >= 0) {
		AVStream* in_stream  = inputFileContext->streams[pkt.stream_index];
		AVStream* out_stream = outputFileContext->streams[pkt.stream_index];
		pkt.pts = av_rescale_q_rnd(pkt.pts, in_stream->time_base, out_stream->time_base, static_cast<AVRounding>(AV_ROUND_NEAR_INF|AV_ROUND_PASS_MINMAX));
		pkt.dts = av_rescale_q_rnd(pkt.dts, in_stream->time_base, out_stream->time_base, static_cast<AVRounding>(AV_ROUND_NEAR_INF|AV_ROUND_PASS_MINMAX));
		pkt.duration = av_rescale_q(pkt.duration, in_stream->time_base, out_stream->time_base);
		pkt.pos = -1;
		av_interleaved_write_frame(outputFileContext, &pkt);
		av_packet_unref(&pkt);
	}

	av_write_trailer(outputFileContext);
	avio_closep(&outputFileContext->pb);
	avformat_free_context(outputFileContext);
	avformat_close_input(&inputFileContext);
	
	
	if (inputFileContext != nullptr) {
		avformat_close_input(&inputFileContext);
		std::cout << "Closed file" << std::endl;
	}
	return 0;
}

