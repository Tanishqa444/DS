
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedListQueue {
private:
    Node* front;
    Node* rear;

public:
    LinkedListQueue() {
        front = nullptr;
        rear = nullptr;
    }

    ~LinkedListQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);

        if (isEmpty()) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }

        Node* temp = front;
        int val = temp->data;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        return val;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }

        return front->data;
    }
};

int main() {
    LinkedListQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.getFront() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "New Front: " << q.getFront() << endl;

    return 0;
}
