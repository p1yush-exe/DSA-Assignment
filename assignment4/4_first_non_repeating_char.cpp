#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// 4) First non-repeating character in a string using Queue
// Sample I/P: a a b c  ->  Sample O/P: a -1 b b

int main() {
    string inStr;
    cout << "Enter characters (e.g., a a b c): ";
    getline(cin, inStr);

    vector<int> freq(256, 0);
    queue<char> q;
    string output = "";

    for (char c : inStr) {
        if (c == ' ') continue; // ignore spaces

        freq[c]++;
        if (freq[c] == 1) {
            q.push(c);
        }

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (q.empty()) {
            output += "-1 ";
        } else {
            output += q.front();
            output += " ";
        }
    }

    if (!output.empty() && output.back() == ' ') {
        output.pop_back(); // remove trailing space
    }

    cout << "Output: " << output << endl;

    return 0;
}
