
#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

bool isPalindrome(const string& str) {
    stack<char> st;
    queue<char> q;

    for (char ch : str) {
        st.push(ch);
        q.push(ch);
    }

    while (!st.empty()) {
        if (st.top() != q.front()) {
            return false;
        }

        st.pop();
        q.pop();
    }

    return true;
}

int main() {
    string str;

    cout << "Enter a word: ";
    cin >> str;

    if (isPalindrome(str)) {
        cout << "Palindrome";
    }
    else {
        cout << "Not Palindrome";
    }

    return 0;
}
