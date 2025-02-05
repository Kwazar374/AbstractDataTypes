#include "QueueArrayRepresentation.hpp"
#include <iostream>

int main() {
    QueueArrayRepresentation<int> queue;
    queue.Enqueue(10);
    queue.Enqueue(20);
    std::cout << queue << std::endl;
}