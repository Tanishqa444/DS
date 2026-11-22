
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

class CircularLinkedList {
private:
    Node* tail;

public:
    CircularLinkedList() {
        tail = nullptr;
    }

    // INSERT AT HEAD
    void insertHead(int val) {
        Node* newNode = new Node(val);

        if (tail == nullptr) {
            tail = newNode;
            tail->next = tail;
            return;
        }

        newNode->next = tail->next;
        tail->next = newNode;
    }

    // INSERT AT TAIL
    void insertTail(int val) {
        Node* newNode = new Node(val);

        if (tail == nullptr) {
            tail = newNode;
            tail->next = tail;
            return;
        }

        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    // INSERT AT POSITION
    void insertAtPosition(int val, int pos) {
        if (pos < 0) {
            cout << "Invalid position\n";
            return;
        }

        if (pos == 0) {
            insertHead(val);
            return;
        }

        if (tail == nullptr) {
            cout << "Invalid position\n";
            return;
        }

        Node* temp = tail->next;
        int i = 0;

        while (i < pos - 1 && temp != tail) {
            temp = temp->next;
            i++;
        }

        if (i != pos - 1) {
            cout << "Invalid position\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        if (temp == tail) {
            tail = newNode;
        }
    }

    // DELETE AT HEAD
    void deleteHead() {
        if (tail == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* head = tail->next;

        if (head == tail) {
            delete tail;
            tail = nullptr;
            return;
        }

        tail->next = head->next;
        delete head;
    }

    // DELETE AT TAIL
    void deleteTail() {
        if (tail == nullptr) {
            cout << "List is empty\n";
            return;
        }

        if (tail->next == tail) {
            delete tail;
            tail = nullptr;
            return;
        }

        Node* temp = tail->next;

        while (temp->next != tail) {
            temp = temp->next;
        }

        Node* target = tail;
        temp->next = tail->next;
        tail = temp;
        delete target;
    }

    // DELETE AT POSITION
    void deleteAtPosition(int pos) {
        if (pos < 0 || tail == nullptr) {
            cout << "Invalid position\n";
            return;
        }

        if (pos == 0) {
            deleteHead();
            return;
        }

        Node* temp = tail->next;
        int i = 0;

        while (i < pos - 1 && temp != tail) {
            temp = temp->next;
            i++;
        }

        if (i != pos - 1 || temp == tail ||
            temp->next == tail->next) {
            cout << "Invalid position\n";
            return;
        }

        Node* target = temp->next;
        temp->next = target->next;

        if (target == tail) {
            tail = temp;
        }

        delete target;
    }

    // SEARCH
    void search(int val) {
        if (tail == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = tail->next;
        int pos = 0;

        do {
            if (temp->data == val) {
                cout << "Element found at position "
                     << pos << endl;
                return;
            }

            temp = temp->next;
            pos++;

        } while (temp != tail->next);

        cout << "Element not found\n";
    }

    // DISPLAY
    void display() {
        if (tail == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = tail->next;

        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);

        cout << "HEAD\n";
    }

    // DESTRUCTOR
    ~CircularLinkedList() {
        while (tail != nullptr) {
            deleteHead();
        }
    }
};

int main() {
    CircularLinkedList l;

    l.insertHead(20);
    l.insertHead(10);
    l.insertTail(40);
    l.insertAtPosition(30, 2);

    cout << "Original list:\n";
    l.display();

    l.search(30);

    l.deleteHead();
    cout << "After deleting head:\n";
    l.display();

    l.deleteTail();
    cout << "After deleting tail:\n";
    l.display();

    l.insertTail(50);
    l.insertTail(60);

    l.deleteAtPosition(1);
    cout << "After deleting position 1:\n";
    l.display();

    return 0;
}
