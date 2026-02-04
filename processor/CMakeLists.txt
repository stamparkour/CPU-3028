cmake_minimum_required(VERSION 3.16)
include(FetchContent)

#source files
set(PROJECT_SOURCES
	"src/source.cpp"
)
set(PROJECT_HEADERS
)

# add the library
add_library(processor STATIC ${PROJECT_SOURCES} ${PROJECT_HEADERS})
add_library(cpu3026::processor ALIAS processor)
target_compile_features(processor PRIVATE cxx_std_23)
target_link_libraries(processor PUBLIC cpu3026::core)

# adds a directory to search when finding header files
target_include_directories(processor 
	PUBLIC "include" 
	PUBLIC "${cpu3026_BINARY_DIR}/core/include"
)

# dependencies
set(BUILD_SHARED_LIBS ON)
