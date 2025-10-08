add_executable(log_level_tests log_level_tests.cpp)
add_executable(logger_tests logger_tests.cpp)
add_executable(module_logger_tests module_logger_tests.cpp)

target_link_libraries(log_level_tests PRIVATE
	log
	GTest::gtest_main
)
target_link_libraries(logger_tests PRIVATE
	log
	GTest::gtest_main
)
target_link_libraries(module_logger_tests PRIVATE
	log
	GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(log_level_tests)
gtest_discover_tests(logger_tests)
gtest_discover_tests(module_logger_tests)
