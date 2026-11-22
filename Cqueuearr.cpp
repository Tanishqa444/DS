
#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front, rear, count, capacity;

public:
    CircularQueue(int cap) {
        capacity = cap;
        front = 0;
        rear = -1;
        count = 0;
        arr = new int[capacity];
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = val;
        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }

        int val = arr[front];
        front = (front + 1) % capacity;
        count--;

        return val;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }

        return arr[front];
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.getFront() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "New Front: " << q.getFront() << endl;

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Front now: " << q.getFront() << endl;

    return 0;
}
