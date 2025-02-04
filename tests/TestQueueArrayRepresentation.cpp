#include <gtest/gtest.h>
#include "../src/QueueArrayRepresentation.hpp"

// Test basic enqueue-dequeue functionality
TEST(QueueArrayTest, EnqueueDequeue) {
    QueueArrayRepresentation<int> queue;
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);

    EXPECT_EQ(queue.Dequeue(), 10);
    EXPECT_EQ(queue.Dequeue(), 20);
    EXPECT_EQ(queue.Dequeue(), 30);
}

// Test behavior of IsEmpty()
TEST(QueueArrayTest, IsEmptyInitially) {
    QueueArrayRepresentation<int> queue;
    EXPECT_TRUE(queue.IsEmpty());
}

// Test exceptions for empty queue operations
TEST(QueueArrayTest, ThrowsOnEmptyDequeue) {
    QueueArrayRepresentation<int> queue;
    EXPECT_THROW(queue.Dequeue(), std::out_of_range);
}
