
#include <iostream>
#include <stack>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// 1. BST Insertion
Node* insertBST(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->data)
        root->left = insertBST(root->left, key);

    else if (key > root->data)
        root->right = insertBST(root->right, key);

    return root;
}

// 2. BST Searching
bool searchBST(Node* root, int key) {
    if (root == nullptr)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return searchBST(root->left, key);

    return searchBST(root->right, key);
}

// 3. Find minimum node
Node* minValueNode(Node* root) {
    Node* cur = root;

    while (cur != nullptr && cur->left != nullptr)
        cur = cur->left;

    return cur;
}

// 4. BST Deletion
Node* deleteBST(Node* root, int key) {
    if (root == nullptr)
        return nullptr;

    if (key < root->data) {
        root->left = deleteBST(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteBST(root->right, key);
    }
    else {
        // Case 1 & 2: No left child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: No right child
        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node* temp = minValueNode(root->right);
        root->data = temp->data;

        root->right = deleteBST(root->right, temp->data);
    }

    return root;
}

// 5. Recursive Preorder: Root Left Right
void preorder(Node* root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// 6. Recursive Inorder: Left Root Right
void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// 7. Recursive Postorder: Left Right Root
void postorder(Node* root) {
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// 8. Iterative Preorder
void preorderIterative(Node* root) {
    if (root == nullptr)
        return;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* cur = st.top();
        st.pop();

        cout << cur->data << " ";

        if (cur->right != nullptr)
            st.push(cur->right);

        if (cur->left != nullptr)
            st.push(cur->left);
    }
}

// 9. Iterative Inorder
void inorderIterative(Node* root) {
    stack<Node*> st;
    Node* cur = root;

    while (cur != nullptr || !st.empty()) {
        while (cur != nullptr) {
            st.push(cur);
            cur = cur->left;
        }

        cur = st.top();
        st.pop();

        cout << cur->data << " ";
        cur = cur->right;
    }
}

// 10. Iterative Postorder (Two Stacks)
void postorderIterative(Node* root) {
    if (root == nullptr)
        return;

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* cur = s1.top();
        s1.pop();

        s2.push(cur);

        if (cur->left != nullptr)
            s1.push(cur->left);

        if (cur->right != nullptr)
            s1.push(cur->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

// 11. Free memory
void deleteTree(Node* root) {
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// ONLY ONE MAIN
int main() {
    Node* root = nullptr;

    // Insert BST nodes
    root = insertBST(root, 50);
    root = insertBST(root, 30);
    root = insertBST(root, 70);
    root = insertBST(root, 20);
    root = insertBST(root, 40);
    root = insertBST(root, 60);
    root = insertBST(root, 80);

    // Recursive traversals
    cout << "Recursive Preorder: ";
    preorder(root);

    cout << "\nRecursive Inorder: ";
    inorder(root);

    cout << "\nRecursive Postorder: ";
    postorder(root);

    // Iterative traversals
    cout << "\n\nIterative Preorder: ";
    preorderIterative(root);

    cout << "\nIterative Inorder: ";
    inorderIterative(root);

    cout << "\nIterative Postorder: ";
    postorderIterative(root);

    // Search
    cout << "\n\nSearching 40: ";
    if (searchBST(root, 40))
        cout << "Found";
    else
        cout << "Not Found";

    // Delete leaf node
    root = deleteBST(root, 20);
    cout << "\nAfter deleting 20: ";
    inorder(root);

    // Delete node with one child
    root = deleteBST(root, 30);
    cout << "\nAfter deleting 30: ";
    inorder(root);

    // Delete node with two children
    root = deleteBST(root, 50);
    cout << "\nAfter deleting 50: ";
    inorder(root);

    cout << endl;

    deleteTree(root);

    return 0;
}
