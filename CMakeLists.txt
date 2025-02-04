cmake_minimum_required(VERSION 3.23)
project(AbstractDataTypes)

set(CMAKE_CXX_VERSION 20)
set(CMAKE_CXX_VERSION_REQUIRED true)

include(FetchContent)

FetchContent_Declare(
    gtest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)

FetchContent_MakeAvailable(gtest)

add_subdirectory(QueueArrayRepresentation)

add_executable(main main.cpp)

target_link_libraries(main ${PROJECT_NAME}-QueueArrayRepresentation)