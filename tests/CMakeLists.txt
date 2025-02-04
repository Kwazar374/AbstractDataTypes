include(FetchContent)

# Fetch Google Test
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# Create executable for tests
add_executable(TestQueueArrayRepresentation TestQueueArrayRepresentation.cpp)

# Link Google Test to the executable
target_link_libraries(TestQueueArrayRepresentation gtest gtest_main)

# Register the tests
add_test(NAME QueueTests COMMAND TestQueueArrayRepresentation)
