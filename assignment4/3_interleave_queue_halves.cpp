#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// 3) Interleave first half of queue with second half
// Example: 4 7 11 20 5 9 -> 4 20 7 5 11 9

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}

int main() {
    queue<int> q;
    int n;
    cout << "Enter EVEN number of elements: ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Number of elements must be even.\n";
        return 1;
    }

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        q.push(val);
    }

    int half = n / 2;
    stack<int> s;

    // Step 1: move first half into stack
    for (int i = 0; i < half; ++i) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: push stack elements back to queue (reversed first half)
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: move first half (originally second half) from front to back
    for (int i = 0; i < half; ++i) {
        q.push(q.front());
        q.pop();
    }

    // Step 4: again push first half to stack
    for (int i = 0; i < half; ++i) {
        s.push(q.front());
        q.pop();
    }

    // Step 5: interleave stack and queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }

    cout << "Interleaved queue: ";
    printQueue(q);

    return 0;
}
