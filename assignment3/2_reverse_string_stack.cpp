#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 2. Reverse a string using stack
int main() {
    string inStr;
    cout << "Enter a string: ";
    getline(cin, inStr);

    stack<char> stk;
    for (char c : inStr) {
        stk.push(c);
    }

    string revStr = "";
    while (!stk.empty()) {
        revStr += stk.top();
        stk.pop();
    }

    cout << "Reversed string: " << revStr << endl;
    return 0;
}
