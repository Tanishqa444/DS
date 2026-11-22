
#include <iostream>
#include <queue>
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

// Build binary tree using queue
Node* buildTree() {
    int x;

    cout << "Enter root (-1 for empty): ";
    cin >> x;

    if (x == -1)
        return nullptr;

    Node* root = new Node(x);

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        int leftValue, rightValue;

        cout << "Left child of " << cur->data << ": ";
        cin >> leftValue;

        cout << "Right child of " << cur->data << ": ";
        cin >> rightValue;

        if (leftValue != -1) {
            cur->left = new Node(leftValue);
            q.push(cur->left);
        }

        if (rightValue != -1) {
            cur->right = new Node(rightValue);
            q.push(cur->right);
        }
    }

    return root;
}

// 1. Recursive Preorder: Root Left Right
void preorder(Node* root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// 2. Recursive Inorder: Left Root Right
void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// 3. Recursive Postorder: Left Right Root
void postorder(Node* root) {
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// 4. Iterative Preorder
void preorderIterative(Node* root) {
    if (root == nullptr)
        return;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* cur = st.top();
        st.pop();

        cout << cur->data << " ";

        // Right first, then left
        if (cur->right)
            st.push(cur->right);

        if (cur->left)
            st.push(cur->left);
    }
}

// 5. Iterative Inorder
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

// 6. Iterative Postorder (Two Stacks)
void postorderIterative(Node* root) {
    if (root == nullptr)
        return;

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* cur = s1.top();
        s1.pop();

        s2.push(cur);

        if (cur->left)
            s1.push(cur->left);

        if (cur->right)
            s1.push(cur->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

// Free allocated tree nodes
void deleteTree(Node* root) {
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Only one main function
int main() {
    Node* root = buildTree();

    cout << "\nRecursive Preorder: ";
    preorder(root);

    cout << "\nRecursive Inorder: ";
    inorder(root);

    cout << "\nRecursive Postorder: ";
    postorder(root);

    cout << "\n\nIterative Preorder: ";
    preorderIterative(root);

    cout << "\nIterative Inorder: ";
    inorderIterative(root);

    cout << "\nIterative Postorder: ";
    postorderIterative(root);

    cout << endl;

    deleteTree(root);

    return 0;
}
