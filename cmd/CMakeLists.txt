cmake_minimum_required(VERSION 3.16)
include(FetchContent)

#source files
set(PROJECT_SOURCES
	"src/source.cpp"
)
set(PROJECT_HEADERS
)

# add the exectuable
add_executable(cmd ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_compile_features(cmd PRIVATE cxx_std_23)
target_link_libraries(cmd cpu3026::cpu3026)

# dependencies
set(BUILD_SHARED_LIBS ON)
