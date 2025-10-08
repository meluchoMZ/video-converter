#pragma once

#include <mutex>
#include <string>

#include "LogLevel.h"

namespace compute::log
{

	/**
	 * Logger class that acts as a static backend to centralized logging
	 */
	// TODO make final
	class Logger
	{
		protected:
			std::mutex _logLock;
			Logger() = default;
		public:
			/**
			 * Returns an instance of Logger
			 * @return a pointer to a Logger instance
			 */
			static Logger& getInstance();

			/**
			 * Logs the desired message accordingly to the selected log level
			 */
			void log(LogLevel logLevel, std::string msg);
	};
} // namespace compute::log
