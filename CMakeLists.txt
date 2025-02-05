# How to use Google Tests with CMake:
# https://google.github.io/googletest/quickstart-cmake.html

cmake_minimum_required(VERSION 3.23)
project(DataStructures)

set(CMAKE_CXX_VERSION 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    gtest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(gtest)

enable_testing()

set(CTEST_DROP_METHOD "none") # disappear missing dart file warning 

add_subdirectory(QueueArrayRepresentation)

add_executable(main main.cpp)

target_link_libraries(main ${PROJECT_NAME}-QueueArrayRepresentation)