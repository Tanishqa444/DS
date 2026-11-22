
#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

public:
    DynamicArray(int capacity = 2) {
        if (capacity < 1) {
            capacity = 2;
        }

        this->capacity = capacity;
        size = 0;
        arr = new int[capacity];
    }

    void resize(int newCapacity) {
        int* newArr = new int[newCapacity];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

    void insertBeginning(int val) {
        if (size == capacity) {
            resize(2 * capacity);
        }

        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = val;
        size++;
    }

    void insertEnd(int val) {
        if (size == capacity) {
            resize(2 * capacity);
        }

        arr[size] = val;
        size++;
    }

    void insertAtPosition(int val, int pos) {
        if (pos < 0 || pos > size) {
            cout << "Invalid position\n";
            return;
        }

        if (size == capacity) {
            resize(2 * capacity);
        }

        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }

        arr[pos] = val;
        size++;
    }

    void deleteBeginning() {
        if (size == 0) {
            cout << "Array is empty\n";
            return;
        }

        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    void deleteEnd() {
        if (size == 0) {
            cout << "Array is empty\n";
            return;
        }

        size--;
    }

    void deleteAtPosition(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position\n";
            return;
        }

        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    void search(int val) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == val) {
                cout << "Element found at position " << i << endl;
                return;
            }
        }

        cout << "Element not found\n";
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void showInfo() {
        cout << "Size: " << size << endl;
        cout << "Capacity: " << capacity << endl;
    }

    ~DynamicArray() {
        delete[] arr;
    }

   // DynamicArray(const DynamicArray&) = delete;
    //DynamicArray& operator=(const DynamicArray&) = delete;
};

int main() {
    DynamicArray a;

    a.insertBeginning(20);
    a.insertBeginning(10);
    a.insertEnd(40);
    a.insertAtPosition(30, 2);

    cout << "Original array: ";
    a.display();
    a.showInfo();

    a.search(30);

    a.deleteBeginning();
    cout << "After deleting beginning: ";
    a.display();

    a.deleteEnd();
    cout << "After deleting end: ";
    a.display();

    a.insertEnd(50);
    a.insertEnd(60);

    a.deleteAtPosition(1);
    cout << "After deleting position 1: ";
    a.display();

    a.showInfo();

    return 0;
}
