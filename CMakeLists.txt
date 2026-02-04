cmake_minimum_required(VERSION 3.16)

# set the project name
project(cpu3026 VERSION 0.1.0 LANGUAGES C CXX)

#options
option(BUILD_CMDLINE_TOOL "build command line executable" ON)
option(TEST_CPU3026 "run tests on cpu3026" ON)


#config
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# include subdirectories
add_subdirectory(core)
if(TEST_CPU3026)
	add_subdirectory(cmd)
endif()
if(BUILD_CMDLINE_TOOL)
	add_subdirectory(test)
endif()
