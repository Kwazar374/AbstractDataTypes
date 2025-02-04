add_library(
    ${PROJECT_NAME}-QueueArrayRepresentation
    QueueArrayRepresentation.cpp
)

target_include_directories(
    ${PROJECT_NAME}-QueueArrayRepresentation PUBLIC
    .
)

add_executable(
    QueueArrayRepresentationTest
    tests/QueueArrayRepresentationTest.cpp
)

target_link_libraries(
    QueueArrayRepresentationTest
    ${PROJECT_NAME}-QueueArrayRepresentation
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(QueueArrayRepresentationTest)