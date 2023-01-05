add_library(lib_utils FileLoader.cpp FileLoader.hpp)

target_include_directories(lib_utils PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")