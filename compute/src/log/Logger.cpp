#include <chrono>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

#include "Logger.h"
#include "LogLevel.h"

namespace compute::log
{
	Logger& Logger::getInstance()
	{
		// Thread safe static initialization since C++11
		static Logger instance;
		return instance;
	}

	void Logger::log(LogLevel logLevel, std::string msg)
	{
		const std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    		const std::time_t t_c = std::chrono::system_clock::to_time_t(now);
		std::stringstream timestampStream;
		timestampStream << std::put_time(std::localtime(&t_c), "%Y-%m-%d %H:%M:%S");
		std::string timestamp = timestampStream.str();
		while(!_logLock.try_lock()) {
			// TODO change this to be asyncronous with a queue
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
		std::cout << timestamp << " - " << utils::logLevelToString(logLevel) << " - " << msg << std::endl;
		_logLock.unlock();
	}
} // namespace compute::log

