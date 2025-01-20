#ifndef QUEUE_ARRAY_REPRESENTATION_H
#define QUEUE_ARRAY_REPRESENTATION_H

#include <algorithm>

template <typename T>
class QueueArrayRepresentation
{
private:
    T* array;
    size_t arraySize = 10;
    size_t front = 0;
    size_t back = 0;

public:
    QueueArrayRepresentation(size_t arraySize = 8) 
        : arraySize(arraySize), array(new T[arraySize]) {}
    ~QueueArrayRepresentation() {
        delete[] array;
    }

    void Enqueue(T element) {
        if (back+1 >= arraySize) {
            T* tmp = new T[arraySize * 2];
            std::copy(array, array + arraySize, tmp);
            arraySize *= 2;
            delete[] array;
            array = tmp;
        }
        array[back++] = element;
    }

    void Dequeue() {
        if (back > front) {
            front++;
            if (static_cast<double>(back - front) / static_cast<double>(arraySize) < 0.3) {
                T* tmp = new T[arraySize / 2];
                std::copy(array + front, array + back, tmp);
                arraySize /= 2;
                delete[] array;
                array = tmp;
            }
        }
    }
};

#endif