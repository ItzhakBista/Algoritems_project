//mail: itzhak173@gmail.com

#pragma once

template <typename T>
class Queue {
private:
    T* data;
    int front;
    int rear;
    int capacity;
    int count;

public:
    Queue(int size = 100) : front(0), rear(0), capacity(size), count(0){
        data = new T[capacity];
    }

    ~Queue() {
        delete[] data;
    }

    void enqueue(T value) {
        if (count == capacity) return;
        data[rear] = value;
        rear = (rear + 1) % capacity;
        count++;
    }

    T dequeue() {
        if (isEmpty()) return T();
        T value = data[front];
        front = (front + 1) % capacity;
        count--;
        return value;
    }

    bool isEmpty() const {
        return count == 0;
    }
};