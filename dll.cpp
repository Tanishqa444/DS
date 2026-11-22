#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // INSERT AT HEAD
    void insertHead(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // INSERT AT TAIL
    void insertTail(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
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

        Node* temp = head;
        int i = 0;

        while (temp != nullptr && i < pos - 1) {
            temp = temp->next;
            i++;
        }

        if (temp == nullptr) {
            cout << "Invalid position\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        else {
            tail = newNode;
        }

        temp->next = newNode;
    }

    // DELETE AT HEAD
    void deleteHead() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }

        delete temp;
    }

    // DELETE AT TAIL
    void deleteTail() {
        if (tail == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = tail;
        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }

        delete temp;
    }

    // DELETE AT POSITION
    void deleteAtPosition(int pos) {
        if (pos < 0 || head == nullptr) {
            cout << "Invalid position or empty list\n";
            return;
        }

        Node* temp = head;
        int i = 0;

        while (temp != nullptr && i < pos) {
            temp = temp->next;
            i++;
        }

        if (temp == nullptr) {
            cout << "Invalid position\n";
            return;
        }

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }
        else {
            head = temp->next;
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        else {
            tail = temp->prev;
        }

        delete temp;
    }

    // SEARCH
    void search(int val) {
        Node* temp = head;
        int pos = 0;

        while (temp != nullptr) {
            if (temp->data == val) {
                cout << "Element found at position "
                     << pos << endl;
                return;
            }

            temp = temp->next;
            pos++;
        }

        cout << "Element not found\n";
    }

    // DISPLAY FORWARD
    void displayForward() {
        Node* temp = head;

        cout << "NULL <-> ";

        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // DISPLAY BACKWARD
    void displayBackward() {
        Node* temp = tail;

        cout << "NULL <-> ";

        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }

        cout << "NULL\n";
    }

    // DESTRUCTOR
    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList l;

    l.insertHead(20);
    l.insertHead(10);
    l.insertTail(40);
    l.insertAtPosition(30, 2);

    cout << "Original list:\n";
    l.displayForward();

    cout << "Backward traversal:\n";
    l.displayBackward();

    l.search(30);

    l.deleteHead();
    cout << "After deleting head:\n";
    l.displayForward();

    l.deleteTail();
    cout << "After deleting tail:\n";
    l.displayForward();

    l.insertTail(50);
    l.insertTail(60);

    l.deleteAtPosition(1);
    cout << "After deleting position 1:\n";
    l.displayForward();

    return 0;
}
