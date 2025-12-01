#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 3. Check if an expression has balanced parentheses
bool isBalanced(const string& exp) {
    stack<char> stk;
    for (char c : exp) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stk.empty()) return false;
            char top_c = stk.top();
            stk.pop();
            if (c == ')' && top_c != '(') return false;
            if (c == ']' && top_c != '[') return false;
            if (c == '}' && top_c != '{') return false;
        }
    }
    return stk.empty();
}

int main() {
    string exp;
    cout << "Enter expression: ";
    getline(cin, exp);

    if (isBalanced(exp))
        cout << "Expression has balanced parentheses." << endl;
    else
        cout << "Expression does NOT have balanced parentheses." << endl;

    return 0;
}
