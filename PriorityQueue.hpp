//mail: itzhak173@gmail.com

#pragma once

template <typename T, typename P>
class PriorityQueue {
private:
    struct Node {
        T value;
        P priority;
    };
    
    Node* heap;
    int capacity;
    int size;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index].priority < heap[parent].priority) {
                Node temp = heap[index];
                heap[index] = heap[parent];
                heap[parent] = temp;
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        while (2 * index + 1 < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = left;

            if (right < size && heap[right].priority < heap[left].priority) {
                smallest = right;
            }

            if (heap[index].priority > heap[smallest].priority) {
                Node temp = heap[index];
                heap[index] = heap[smallest];
                heap[smallest] = temp;
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    PriorityQueue(int cap = 100) : capacity(cap), size(0) {
        heap = new Node[capacity];
    }
    
    ~PriorityQueue() {
        delete[] heap;
    }

    void insert(T value, P priority) {
        if (size == capacity) return;
        heap[size] = {value, priority};
        heapifyUp(size);
        size++;
    }

    T extractMin() {
        if (size == 0) return T();
        T minValue = heap[0].value;
        heap[0] = heap[--size];
        heapifyDown(0);
        return minValue;
    }

    bool isEmpty() const {
        return size == 0;
    }
};