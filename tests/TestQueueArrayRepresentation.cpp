#include <gtest/gtest.h>
#include "../src/QueueArrayRepresentation.hpp"

TEST(QueueArrayTest, EnqueueDequeue) {
    QueueArrayRepresentation<int> queue;
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);

    EXPECT_EQ(queue.Dequeue(), 10);
    EXPECT_EQ(queue.Dequeue(), 20);
    EXPECT_EQ(queue.Dequeue(), 30);
}
