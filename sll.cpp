
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
    void insertHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // 2. INSERT AT TAIL
    void insertTail(int val) {
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

    // 3. INSERT AT POSITION (0-based)
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
        temp->next = newNode;
    }

    // 4. DELETE AT HEAD
    void deleteHead() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // 5. DELETE AT TAIL
    void deleteTail() {
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

    // 6. DELETE AT POSITION (0-based)
    void deleteAtPosition(int pos) {
        if (pos < 0 || head == nullptr) {
            cout << "Invalid position or empty list\n";
            return;
        }

        if (pos == 0) {
            deleteHead();
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
                cout << "Element found at position "
                     << pos << endl;
                return;
            }

            temp = temp->next;
            pos++;
        }

        cout << "Element not found\n";
    }

    // 8. DISPLAY
    void display() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // 9. REVERSE LINKED LIST
    void reverseList() {
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

    // 10. FIND MIDDLE NODE
    Node* findMiddle() {
        if (head == nullptr)
            return nullptr;

        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // 11. DETECT CYCLE
    bool hasCycle() {
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }

    // 12. MERGE TWO SORTED LINKED LISTS
    // Merges nodes from l1 and l2 into this list.
    // Both input lists must already be sorted.
    void mergeTwoLists(SinglyLinkedList& l1,
                       SinglyLinkedList& l2) {

        // Avoid merging a list with itself
        if (this == &l1 || this == &l2 || &l1 == &l2) {
            cout << "Use three different lists\n";
            return;
        }

        // Clear current destination list
        while (head != nullptr) {
            deleteHead();
        }

        Node dummy(0);
        Node* tail = &dummy;

        Node* a = l1.head;
        Node* b = l2.head;

        while (a != nullptr && b != nullptr) {
            if (a->data <= b->data) {
                tail->next = a;
                a = a->next;
            }
            else {
                tail->next = b;
                b = b->next;
            }

            tail = tail->next;
        }

        tail->next = (a != nullptr) ? a : b;

        head = dummy.next;

        // Nodes now belong to the merged list
        l1.head = nullptr;
        l2.head = nullptr;
    }

    // DESTRUCTOR
    ~SinglyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// ONLY ONE MAIN - NO MENU
int main() {

    SinglyLinkedList l;

    // Insert operations
    l.insertHead(20);
    l.insertHead(10);
    l.insertTail(30);
    l.insertTail(40);
    l.insertAtPosition(25, 2);

    cout << "Original List: ";
    l.display();

    // Search
    l.search(25);

    // Find middle
    Node* middle = l.findMiddle();

    if (middle != nullptr)
        cout << "Middle Node: " << middle->data << endl;

    // Reverse
    l.reverseList();
    cout << "Reversed List: ";
    l.display();

    // Detect cycle
    if (l.hasCycle())
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    // Delete operations
    l.deleteHead();
    l.deleteTail();
    l.deleteAtPosition(1);

    cout << "After Deletions: ";
    l.display();

    // Merge two sorted linked lists
    SinglyLinkedList l1, l2, merged;

    l1.insertTail(1);
    l1.insertTail(3);
    l1.insertTail(5);

    l2.insertTail(2);
    l2.insertTail(4);
    l2.insertTail(6);

    cout << "\nSorted List 1: ";
    l1.display();

    cout << "Sorted List 2: ";
    l2.display();

    merged.mergeTwoLists(l1, l2);

    cout << "Merged Sorted List: ";
    merged.display();

    return 0;
}
