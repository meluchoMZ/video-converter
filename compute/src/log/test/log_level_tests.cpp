#include <gtest/gtest.h>

#include "LogLevel.h"

/**
 * compute::log::utils::logLevelToString() method tests
 */

using namespace compute::log;

TEST(logLevelTests, ConvertNONEToString)
{
	EXPECT_EQ(utils::logLevelToString(LogLevel::NONE), "NONE");
}

TEST(logLevelTests, ConvertINFOToString)
{
	EXPECT_EQ(utils::logLevelToString(LogLevel::INFO), "INFO");
}

TEST(logLevelTests, ConvertWARNToString)
{
	EXPECT_EQ(utils::logLevelToString(LogLevel::WARN), "WARN");
}

TEST(logLevelTests, ConvertERRORToString)
{
	EXPECT_EQ(utils::logLevelToString(LogLevel::ERROR), "ERROR");
}

TEST(logLevelTests, ConvertDEBUGToString)
{
	EXPECT_EQ(utils::logLevelToString(LogLevel::DEBUG), "DEBUG");
}

TEST(logLevelTests, CheckVerbosityPrecedenceINFOtoWARN)
{
	EXPECT_TRUE(LogLevel::INFO < LogLevel::WARN);
}

TEST(LogLevelTests, CheckVerbosityPrecedenceWARNtoERROR)
{
	EXPECT_TRUE(LogLevel::WARN < LogLevel::ERROR);
}

TEST(LogLevelTests, CheckVerbosityPrecedenceERRORtoDEBUG)
{
	EXPECT_TRUE(LogLevel::ERROR < LogLevel::DEBUG);
}

TEST(LogLevelTests, CheckVerbosityPrecedenceDEBUGToERROR)
{
	EXPECT_TRUE(LogLevel::DEBUG > LogLevel::ERROR);
}

