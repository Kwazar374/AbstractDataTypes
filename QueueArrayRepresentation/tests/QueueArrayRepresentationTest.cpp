#include <gtest/gtest.h>
#include <QueueArrayRepresentation.hpp>

// Constructor and IsEmpty()
TEST(QueueArrayRepresentationTest, ConstructorAndIsEmpty) {
    QueueArrayRepresentation<int> queue;
    EXPECT_TRUE(queue.IsEmpty());
    EXPECT_EQ(queue.Size(), 0);
}

// Enque() and Size()

// Deque() and order of returned values

// Front() and Back()

// Deque() on empty queue

// Copy Constructor and assignment operator

// Resize when queue is full (there's no place at the end)

// Clear()

// ostream operator<<