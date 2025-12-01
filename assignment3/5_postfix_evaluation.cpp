#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <cctype>

using namespace std;

// 5. Evaluate a Postfix expression (single-digit operands)
int evalPostfix(const string& exp) {
    stack<int> valStk;

    for (char c : exp) {
        if (isdigit(static_cast<unsigned char>(c))) {
            valStk.push(c - '0');
        } else if (c == ' ') {
            continue;
        } else {
            if (valStk.size() < 2) {
                cout << "Invalid postfix expression.\n";
                return 0;
            }
            int op2 = valStk.top(); valStk.pop();
            int op1 = valStk.top(); valStk.pop();

            switch (c) {
                case '+': valStk.push(op1 + op2); break;
                case '-': valStk.push(op1 - op2); break;
                case '*': valStk.push(op1 * op2); break;
                case '/': valStk.push(op1 / op2); break;
                case '^': valStk.push(static_cast<int>(pow(op1, op2))); break;
                default:
                    cout << "Unknown operator: " << c << endl;
                    return 0;
            }
        }
    }
    return valStk.top();
}

int main() {
    string exp;
    cout << "Enter a postfix expression (e.g., 23*5+): ";
    getline(cin, exp);

    int res = evalPostfix(exp);
    cout << "Result: " << res << endl;

    return 0;
}
