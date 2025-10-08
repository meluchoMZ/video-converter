# All modules to compile
add_subdirectory(log)

# Library definition as an umbrella library for all modules
add_library(video-converter-libs INTERFACE)

# All modules to link to the umbrella library
target_link_libraries(video-converter-libs INTERFACE
	log
)
