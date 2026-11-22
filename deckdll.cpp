
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class Deque {
    Node* front;
    Node* rear;

public:
    Deque() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void insertFront(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void insertRear(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }

        Node* temp = front;

        if (front == rear) {
            front = rear = nullptr;
        }
        else {
            front = front->next;
            front->prev = nullptr;
        }

        delete temp;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }

        Node* temp = rear;

        if (front == rear) {
            front = rear = nullptr;
        }
        else {
            rear = rear->prev;
            rear->next = nullptr;
        }

        delete temp;
    }

    void peekFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Front: " << front->data << endl;
    }

    void peekRear() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Rear: " << rear->data << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        Node* temp = front;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    ~Deque() {
        while (!isEmpty()) {
            deleteFront();
        }
    }
};

int main() {
    Deque d;

    d.insertRear(10);
    d.insertRear(20);
    d.insertFront(5);
    d.insertFront(2);

    d.display();

    d.deleteFront();
    d.display();

    d.deleteRear();
    d.display();

    d.peekFront();
    d.peekRear();

    return 0;
}
