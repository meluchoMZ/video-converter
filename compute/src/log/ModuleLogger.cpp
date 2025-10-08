#include <string>

#include "Logger.h"
#include "LogLevel.h"
#include "ModuleLogger.h"

namespace compute::log
{
	ModuleLogger::ModuleLogger(const std::string moduleName)
	{
		// by default all loggers are initialized as default
		this->_moduleName = moduleName;
		this->_logLevel = LogLevel::ERROR;
	}

	std::string ModuleLogger::wrapMessage(const std::string msg)
	{
		return "[" + _moduleName + "] " + msg;
	}

	void ModuleLogger::delegate(LogLevel logLevel, const std::string msg)
	{
		// logs are only written if the verbosity is lesser than set
		if (logLevel > this->_logLevel) {
			return;
		}
		Logger::getInstance().log(logLevel, wrapMessage(msg));
	}

	void ModuleLogger::info(const std::string msg)
	{
		delegate(LogLevel::INFO, msg);
	}

	void ModuleLogger::warn(const std::string msg)
	{
		delegate(LogLevel::WARN, msg);
	}

	void ModuleLogger::error(const std::string msg)
	{
		delegate(LogLevel::ERROR, msg);
	}

	void ModuleLogger::debug(const std::string msg)
	{
		delegate(LogLevel::DEBUG, msg);
	}

	void ModuleLogger::setLogLevel(LogLevel logLevel)
	{
		this->_logLevel = logLevel;
	}
	
} // namespace compute::log

