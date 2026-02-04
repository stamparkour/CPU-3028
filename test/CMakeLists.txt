cmake_minimum_required(VERSION 3.16)
include(FetchContent)

#source files
set(PROJECT_SOURCES
	"src/source.cpp"
)
set(PROJECT_HEADERS
)

# add the executable
add_executable(test ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_compile_features(test PRIVATE cxx_std_23)
target_link_libraries(cmd cpu3026::core)

# dependencies
set(BUILD_SHARED_LIBS ON)

include(gtest)
target_link_libraries(test GTest::gtest_main)


#google test required lines
include(GoogleTest)
gtest_discover_tests(test)