
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

class LinkedListStack {
private:
    Node* top;

public:
    LinkedListStack() {
        top = nullptr;
    }

    ~LinkedListStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }

        Node* temp = top;
        int val = temp->data;
        top = top->next;
        delete temp;

        return val;
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return top->data;
    }
};

int main() {
    LinkedListStack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.peek() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "New Top: " << s.peek() << endl;

    return 0;
}
