cmake_minimum_required(VERSION 3.16)
include(FetchContent)

#source files
set(PROJECT_SOURCES
	"src/source.cpp"
)
set(PROJECT_HEADERS
)

# add the library
add_library(cpu3026_core STATIC ${PROJECT_SOURCES} ${PROJECT_HEADERS})
add_library(cpu3026::core ALIAS cpu3026_core)
target_compile_features(cpu3026_core PRIVATE cxx_std_23)

# adds a directory to search when finding header files
target_include_directories(cpu3026_core 
	PUBLIC "include" 
	PUBLIC "${cpu3026_BINARY_DIR}/core/include" 
)

# dependencies
set(BUILD_SHARED_LIBS ON)


# set the configure file for the project
configure_file("include/cpu3026/cpu3026_config.h.in" "include/cpu3026/cpu3026_config.h")
