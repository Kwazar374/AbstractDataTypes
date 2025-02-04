add_library(
    ${PROJECT_NAME}-QueueArrayRepresentation
    QueueArrayRepresentation.cpp
)

target_include_directories(
    ${PROJECT_NAME}-QueueArrayRepresentation PUBLIC
    .
)