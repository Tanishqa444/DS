
#include <iostream>
using namespace std;

class ArrayStack {
private:
    int* arr;
    int top;
    int capacity;

public:
    ArrayStack(int cap) {
        capacity = cap;
        top = -1;
        arr = new int[capacity];
    }

    ~ArrayStack() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = val;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return arr[top];
    }
};

int main() {
    ArrayStack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.peek() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "New Top: " << s.peek() << endl;

    return 0;
}
