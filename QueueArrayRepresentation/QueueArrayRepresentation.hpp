#ifndef QUEUE_ARRAY_REPRESENTATION_H
#define QUEUE_ARRAY_REPRESENTATION_H

#include <algorithm>
#include <stdexcept>
#include <iostream>

template <typename T>
class QueueArrayRepresentation
{
private:
    T* array;
    size_t arraySize = 8;
    size_t front = 0;
    size_t back = 0;

public:
    QueueArrayRepresentation(size_t arraySize = 8) 
        : arraySize(arraySize), array(new T[arraySize]) {}
    ~QueueArrayRepresentation() noexcept{
        delete[] array;
    }
    QueueArrayRepresentation (const QueueArrayRepresentation& other)
        : arraySize(other.arraySize), front(other.front), back(other.back) {
            array = new T[arraySize];
            std::copy(other.array, other.array + arraySize, array);
    }
    QueueArrayRepresentation(QueueArrayRepresentation&& other) noexcept
        : array(other.array), arraySize(other.arraySize), front(other.front), back(other.back) {
            other.array = nullptr;
            other.arraySize = 0;
            other.front = 0;
            other.back = 0;
    }
    QueueArrayRepresentation& operator=(const QueueArrayRepresentation& other) {
        if (this != &other) {
            T* newArray = new T[other.arraySize];
            std::copy(other.array + other.front, other.array + other.back, newArray);
            delete[] array;
            array = newArray;
            arraySize = other.arraySize;
            back = other.back - other.front;
            front = 0;
            
        }
        return *this;
    }
    QueueArrayRepresentation& operator=(QueueArrayRepresentation&& other) noexcept {
        if (this != &other) {
            delete[] array;
            array = other.array;
            arraySize = other.arraySize;
            front = other.front;
            back = other.back;
            other.array = nullptr;
            other.arraySize = 0;
            other.front = 0;
            other.back = 0;
        }
        return *this;
    }

    void Enqueue(T element) {
        if (back >= arraySize) {
            T* tmp = new T[arraySize * 2];
            std::copy(array + front, array + back, tmp);
            back -= front;
            front = 0;
            arraySize *= 2;
            delete[] array;
            array = tmp;
        }
        array[back++] = element;
    }

    T Dequeue() {
        if (!IsEmpty()) {
            T result = array[front];
            front++;
            if ((back - front) < (arraySize * 0.25) && arraySize > 16) {
                T* tmp = new T[arraySize / 2];
                std::copy(array + front, array + back, tmp);
                back -= front;
                front = 0;
                arraySize /= 2;
                delete[] array;
                array = tmp;
            }
            return result;
        }
        else {
            throw std::out_of_range("Queue is empty!");
        }
    }

    bool IsEmpty() const {
        return back == front;
    }

    T Front() const {
        if (!IsEmpty()) {
            return array[front];
        }
        else {
            throw std::out_of_range("Queue is empty!");
        }
    }

    T Back() const {
        if (!IsEmpty()) {
            return array[back-1];
        }
        else {
            throw std::out_of_range("Queue is empty!");
        }
    }
    
    void Clear(size_t newSize = 8) {
        delete[] array;
        arraySize = newSize;
        array = new T[arraySize];
        front = back = 0;
    }

    size_t Size() const {
        return back - front;
    }

    size_t Capacity() const {
        return arraySize;
    }

    friend std::ostream& operator<<(std::ostream& os, const QueueArrayRepresentation<T>& queue) {
        os << "[";
        if (!queue.IsEmpty()) {
            for (size_t i = queue.front; i < queue.back - 1; ++i) {
                os << queue.array[i] << " ";
            }
            os << queue.array[queue.back-1];
        }
        os << "]";
        return os;
    }
};

#endif