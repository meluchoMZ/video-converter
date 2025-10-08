#pragma once

#include <string>

#include "Logger.h"
#include "LogLevel.h"

namespace compute::log
{
	class ModuleLogger
	{
		private:
			LogLevel _logLevel;
			std::string _moduleName;
			std::string wrapMessage(const std::string msg);
			void delegate(LogLevel logLevel, const std::string msg);

		public:
			/**
			 * Class constructor
			 * @param the name of the class or module to log
			 * @return a ModuleLogger class
			 */
			ModuleLogger(const std::string moduleName);

			/**
			 * Logs with LogLevel::INFO
			 */
			void info(const std::string msg);

			/**
			 * Logs with LogLevel::WARN
			 */
			void warn(const std::string msg);

			/**
			 * Logs with LogLevel::ERROR
			 */
			void error(const std::string msg);

			/**
			 * Logs with LogLevel::DEBUG
			 */
			void debug(const std::string msg);

			/**
			 * Sets a LogLevel
			 */
			void setLogLevel(LogLevel logLevel);
	};
} // namespace compute::log

