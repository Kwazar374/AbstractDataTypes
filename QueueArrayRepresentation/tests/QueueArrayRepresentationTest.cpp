#include <gtest/gtest.h>
#include <QueueArrayRepresentation.hpp>

// Constructor and IsEmpty()
TEST(QueueArrayRepresentationTest, DefaultConstructor_IsEmpty_Size) {
    QueueArrayRepresentation<int> queue;
    EXPECT_TRUE(queue.IsEmpty());
    EXPECT_EQ(queue.Size(), 0);
}

// Enque() and Size()
TEST(QueueArrayRepresentationTest, Enque_IsEmpty_Size) {
    QueueArrayRepresentation<int> queue;
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);

    EXPECT_EQ(queue.Size(), 3);
    EXPECT_FALSE(queue.IsEmpty());
}

// Deque() and the order of returned values
TEST(QueueArrayRepresentationTest, Deque_OrderOfReturnedValues) {
    QueueArrayRepresentation<int> queue;
    queue.Enqueue(5);
    queue.Enqueue(10);
    queue.Enqueue(15);

    EXPECT_EQ(queue.Dequeue(), 5);
    EXPECT_EQ(queue.Dequeue(), 10);
    EXPECT_EQ(queue.Dequeue(), 15);

    EXPECT_EQ(queue.Size(), 0);
    EXPECT_TRUE(queue.IsEmpty());
}

// Front() and Back()
TEST(QueueArrayRepresentationTest, Front_Back) {
    QueueArrayRepresentation<int> queue;
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);

    EXPECT_EQ(queue.Front(), 1);
    EXPECT_EQ(queue.Back(), 4);
}

// Deque() on empty queue
TEST(QueueArrayRepresentationTest, DequeOnEmptyQueue) {
    QueueArrayRepresentation<int> queue;
    EXPECT_THROW(queue.Dequeue(), std::out_of_range);
}

// Copy Constructor and assignment operator
TEST(QueueArrayRepresentationTest, CopyConstructor_AssignmentOperator) {
    QueueArrayRepresentation<int> queue1;
    queue1.Enqueue(1);
    queue1.Enqueue(2);
    queue1.Enqueue(3);

    QueueArrayRepresentation<int> queue2 = queue1; // Copy Constructor
    EXPECT_EQ(queue2.Size(), 3);
    EXPECT_EQ(queue2.Dequeue(), 1);

    QueueArrayRepresentation<int> queue3;
    queue3 = queue1; // Assignment Operator
    EXPECT_EQ(queue3.Size(), 3);
    EXPECT_EQ(queue3.Dequeue(), 1);
}

// Capacity Resize when queue is full (there's no place at the end)
TEST(QueueTest, Capacity_Resize) {
    QueueArrayRepresentation<int> queue(2);
    EXPECT_EQ(queue.Capacity(), 2);
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3); // Resize

    EXPECT_EQ(queue.Capacity(), 4);
}

// Clear()
TEST(QueueArrayRepresentationTest, Clear) {
    QueueArrayRepresentation<int> queue;
    queue.Enqueue(5);
    queue.Enqueue(10);
    queue.Clear();

    EXPECT_TRUE(queue.IsEmpty());
    EXPECT_EQ(queue.Size(), 0);
    EXPECT_EQ(queue.Capacity(), 8);
}

// Stream Operator (ostream operator<<)
TEST(QueueArrayRepresentationTest, StreamOperator) {
    QueueArrayRepresentation<int> queue;
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);

    std::ostringstream oss;
    oss << queue;
    EXPECT_EQ(oss.str(), "[1; 2; 3]");
}