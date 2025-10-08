add_library(log STATIC
	LogLevel.h 
	Logger.h 
	Logger.cpp
	ModuleLogger.h
	ModuleLogger.cpp
)

target_include_directories(log PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if(BUILD_TESTS)
	add_subdirectory(test)
endif()

