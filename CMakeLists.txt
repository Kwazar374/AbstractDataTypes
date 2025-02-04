cmake_minimum_required(VERSION 3.10)
project(AbstractDataTypes)

set(CMAKE_CXX_STANDARD 17)

# Add directory with source code
include_directories(src)

# Enable testing
enable_testing()
add_subdirectory(tests)