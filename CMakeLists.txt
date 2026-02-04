cmake_minimum_required(VERSION 3.16)

# set the project name
project(cpu3026 VERSION 0.1.0 LANGUAGES C CXX)

#options
option(CPU3026_PYBIND "generate pybind library" ON)


#config
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# include libraries
add_subdirectory(core)
add_subdirectory(memory)
add_subdirectory(processor)

# add global library
add_library(cpu3026 INTERFACE)
add_library(cpu3026::cpu3026 ALIAS cpu3026)
target_link_libraries(cpu3026 INTERFACE cpu3026::core cpu3026::memory cpu3026::processor)

#add executables
add_subdirectory(cmd)
add_subdirectory(test)
add_subdirectory(cpu3026_py)

#project warnings
if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()