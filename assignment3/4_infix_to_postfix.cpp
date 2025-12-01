#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

// 4. Convert Infix expression to Postfix
int prec(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

string infixToPostfix(const string& inFix) {
    stack<char> stk;
    string postFix = "";

    for (char c : inFix) {
        if (isalnum(static_cast<unsigned char>(c))) {
            postFix += c;
        } else if (c == '(') {
            stk.push(c);
        } else if (c == ')') {
            while (!stk.empty() && stk.top() != '(') {
                postFix += stk.top();
                stk.pop();
            }
            if (!stk.empty()) stk.pop(); // pop '('
        } else { // operator
            while (!stk.empty() && prec(c) <= prec(stk.top())) {
                postFix += stk.top();
                stk.pop();
            }
            stk.push(c);
        }
    }

    while (!stk.empty()) {
        postFix += stk.top();
        stk.pop();
    }

    return postFix;
}

int main() {
    string inFix;
    cout << "Enter an infix expression: ";
    getline(cin, inFix);

    string postFix = infixToPostfix(inFix);
    cout << "Postfix expression: " << postFix << endl;

    return 0;
}
