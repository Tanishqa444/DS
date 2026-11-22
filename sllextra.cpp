
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

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // 1. INSERT AT HEAD
    void insertatHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // 2. INSERT AT TAIL
    void insertatTail(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // 3. INSERT AT POSITION
    void insert(int val, int pos) {
        if (pos < 0) {
            cout << "Invalid position\n";
            return;
        }

        if (pos == 0) {
            insertatHead(val);
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
        temp->next = newNode;
    }

    // 4. DELETE AT HEAD
    void deleteatHead() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // 5. DELETE AT TAIL
    void deleteatTail() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;

        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    // 6. DELETE AT POSITION
    void delete_node(int pos) {
        if (pos < 0 || head == nullptr) {
            cout << "Invalid position or empty list\n";
            return;
        }

        if (pos == 0) {
            deleteatHead();
            return;
        }

        Node* temp = head;
        int i = 0;

        while (temp->next != nullptr && i < pos - 1) {
            temp = temp->next;
            i++;
        }

        if (temp->next == nullptr) {
            cout << "Invalid position\n";
            return;
        }

        Node* target = temp->next;
        temp->next = target->next;
        delete target;
    }

    // 7. SEARCH
    void search(int val) {
        Node* temp = head;
        int pos = 0;

        while (temp != nullptr) {
            if (temp->data == val) {
                cout << "Found at position " << pos << endl;
                return;
            }

            temp = temp->next;
            pos++;
        }

        cout << "Element not found\n";
    }

    // 8. SIZE
    void size() {
        Node* temp = head;
        int count = 0;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        cout << "Size: " << count << endl;
    }

    // 9. DISPLAY
    void display() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // 10. REVERSE LINKED LIST
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    // 11. INSERT BEFORE POSITION
    void insertBeforePos(int val, int pos) {
        if (pos < 0 || head == nullptr) {
            cout << "Invalid position\n";
            return;
        }

        if (pos == 0) {
            insertatHead(val);
            return;
        }

        Node* temp = head;
        int i = 0;

        while (temp->next != nullptr && i < pos - 1) {
            temp = temp->next;
            i++;
        }

        if (temp->next == nullptr) {
            cout << "Invalid position\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // 12. INSERT AFTER POSITION
    void insertAfterPos(int val, int pos) {
        if (pos < 0) {
            cout << "Invalid position\n";
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

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // 13. DELETE BEFORE POSITION
    void deleteBeforePos(int pos) {
        if (pos <= 0 || head == nullptr) {
            cout << "Invalid position\n";
            return;
        }

        if (pos == 1) {
            if (head->next == nullptr) {
                cout << "Invalid position\n";
                return;
            }

            deleteatHead();
            return;
        }

        Node* temp = head;
        int i = 0;

        while (temp->next != nullptr && i < pos - 2) {
            temp = temp->next;
            i++;
        }

        if (temp->next == nullptr ||
            temp->next->next == nullptr) {
            cout << "Invalid position\n";
            return;
        }

        Node* target = temp->next;
        temp->next = target->next;
        delete target;
    }

    // 14. DELETE AFTER POSITION
    void deleteAfterPos(int pos) {
        if (pos < 0) {
            cout << "Invalid position\n";
            return;
        }

        Node* temp = head;
        int i = 0;

        while (temp != nullptr && i < pos) {
            temp = temp->next;
            i++;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "No node after this position\n";
            return;
        }

        Node* target = temp->next;
        temp->next = target->next;
        delete target;
    }

    // 15. INSERT BEFORE VALUE
    void insertBeforeValue(int key, int val) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        if (head->data == key) {
            insertatHead(val);
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr &&
               temp->next->data != key) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Value not found\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // 16. INSERT AFTER VALUE
    void insertAfterValue(int key, int val) {
        Node* temp = head;

        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Value not found\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // DESTRUCTOR
    ~SinglyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    SinglyLinkedList(const SinglyLinkedList&) = delete;
    SinglyLinkedList& operator=(const SinglyLinkedList&) = delete;
};

int main() {
    SinglyLinkedList l;

    int choice = 1;

    while (choice != -1) {
        int userChoice;
        int i, n, key;

        cout << "\n========== SLL MENU ==========\n";
        cout << "1. Insert at head\n";
        cout << "2. Insert at tail\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete at head\n";
        cout << "5. Delete at tail\n";
        cout << "6. Delete at position\n";
        cout << "7. Search for an element\n";
        cout << "8. Print size\n";
        cout << "9. Display linked list\n";
        cout << "10. Reverse linked list\n";
        cout << "11. Insert before position\n";
        cout << "12. Insert after position\n";
        cout << "13. Delete before position\n";
        cout << "14. Delete after position\n";
        cout << "15. Insert before value\n";
        cout << "16. Insert after value\n";
        cout << "17. Exit\n";

        cout << "Enter your choice: ";
        if (!(cin >> userChoice)) {
            cout << "Invalid input\n";
            break;
        }

        switch (userChoice) {
        case 1:
            cout << "Enter value: ";
            cin >> i;
            l.insertatHead(i);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> i;
            l.insertatTail(i);
            break;

        case 3:
            cout << "Enter value: ";
            cin >> i;
            cout << "Enter position: ";
            cin >> n;
            l.insert(i, n);
            break;

        case 4:
            l.deleteatHead();
            break;

        case 5:
            l.deleteatTail();
            break;

        case 6:
            cout << "Enter position: ";
            cin >> n;
            l.delete_node(n);
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> i;
            l.search(i);
            break;

        case 8:
            l.size();
            break;

        case 9:
            l.display();
            break;

        case 10:
            l.reverse();
            cout << "Reversed list: ";
            l.display();
            break;

        case 11:
            cout << "Enter value: ";
            cin >> i;
            cout << "Enter position: ";
            cin >> n;
            l.insertBeforePos(i, n);
            break;

        case 12:
            cout << "Enter value: ";
            cin >> i;
            cout << "Enter position: ";
            cin >> n;
            l.insertAfterPos(i, n);
            break;

        case 13:
            cout << "Enter position: ";
            cin >> n;
            l.deleteBeforePos(n);
            break;

        case 14:
            cout << "Enter position: ";
            cin >> n;
            l.deleteAfterPos(n);
            break;

        case 15:
            cout << "Enter existing value: ";
            cin >> key;
            cout << "Enter new value: ";
            cin >> i;
            l.insertBeforeValue(key, i);
            break;

        case 16:
            cout << "Enter existing value: ";
            cin >> key;
            cout << "Enter new value: ";
            cin >> i;
            l.insertAfterValue(key, i);
            break;

        case 17:
            cout << "Exiting\n";
            choice = -1;
            break;

        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }

        if (cin.fail()) {
            cout << "Invalid input\n";
            break;
        }
    }

    return 0;
}