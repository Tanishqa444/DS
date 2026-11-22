
#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

// INSERT AT BEGINNING
int insertBeginning(int arr[], int size, int val) {
    if (size == MAX_SIZE) {
        cout << "Array is full\n";
        return size;
    }

    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = val;
    return size + 1;
}

// INSERT AT END
int insertEnd(int arr[], int size, int val) {
    if (size == MAX_SIZE) {
        cout << "Array is full\n";
        return size;
    }

    arr[size] = val;
    return size + 1;
}

// INSERT AT POSITION
int insertAtPosition(int arr[], int size, int pos, int val) {
    if (size == MAX_SIZE) {
        cout << "Array is full\n";
        return size;
    }

    if (pos < 0 || pos > size) {
        cout << "Invalid position\n";
        return size;
    }

    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = val;
    return size + 1;
}

// DELETE AT BEGINNING
int deleteBeginning(int arr[], int size) {
    if (size == 0) {
        cout << "Array is empty\n";
        return size;
    }

    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    return size - 1;
}

// DELETE AT END
int deleteEnd(int arr[], int size) {
    if (size == 0) {
        cout << "Array is empty\n";
        return size;
    }

    return size - 1;
}

// DELETE AT POSITION
int deleteAtPosition(int arr[], int size, int pos) {
    if (size == 0) {
        cout << "Array is empty\n";
        return size;
    }

    if (pos < 0 || pos >= size) {
        cout << "Invalid position\n";
        return size;
    }

    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    return size - 1;
}

// SEARCH
void search(int arr[], int size, int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) {
            cout << "Element found at position " << i << endl;
            return;
        }
    }

    cout << "Element not found\n";
}

// DISPLAY
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;

    size = insertBeginning(arr, size, 20);
    size = insertBeginning(arr, size, 10);
    size = insertEnd(arr, size, 40);
    size = insertAtPosition(arr, size, 2, 30);

    cout << "Original array: ";
    display(arr, size);

    search(arr, size, 30);

    size = deleteBeginning(arr, size);
    cout << "After deleting beginning: ";
    display(arr, size);

    size = deleteEnd(arr, size);
    cout << "After deleting end: ";
    display(arr, size);

    size = insertEnd(arr, size, 50);
    size = insertEnd(arr, size, 60);

    size = deleteAtPosition(arr, size, 1);
    cout << "After deleting position 1: ";
    display(arr, size);

    return 0;
}
