#pragma once

namespace compute::log
{
	/**
	 * Log levels. Ordered by increasing verbosity
	 */
	enum class LogLevel
	{
		NONE,
		INFO,
		WARN,
		ERROR,
		DEBUG
	};

	namespace utils
	{
		/**
		 * Get the textual representation of a LogLevel
		 */
		inline constexpr const char * logLevelToString(LogLevel logLevel)
		{
			switch (logLevel)
			{
				case LogLevel::INFO:
					return "INFO";
				case LogLevel::WARN:
					return "WARN";
				case LogLevel::ERROR:
					return "ERROR";
				case LogLevel::DEBUG:
					return "DEBUG";
				default:
					return "NONE";
			}
		}
	} // namespace utils
} // namespace compute::log

