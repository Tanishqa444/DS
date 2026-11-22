
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int evaluatePostfix(const string& exp) {
    stack<int> st;

    for (char c : exp) {
        if (isdigit(c)) {
            st.push(c - '0');
        }
        else if (c == '+' || c == '-' || c == '*' ||
                 c == '/' || c == '^' || c == '%') {

            int val2 = st.top();
            st.pop();

            int val1 = st.top();
            st.pop();

            switch (c) {
                case '+':
                    st.push(val1 + val2);
                    break;

                case '-':
                    st.push(val1 - val2);
                    break;

                case '*':
                    st.push(val1 * val2);
                    break;

                case '/':
                    st.push(val1 / val2);
                    break;

                case '^':
                    st.push(pow(val1, val2));
                    break;

                case '%':
                    st.push(val1 % val2);
                    break;
            }
        }
    }

    return st.top();
}

int main() {
    string exp = "23^4+";

    cout << "Result: " << evaluatePostfix(exp) << endl;

    return 0;
}
