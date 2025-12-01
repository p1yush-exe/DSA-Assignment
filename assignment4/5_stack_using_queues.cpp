#include <iostream>
#include <queue>
using namespace std;

// 5) Implement a stack using
// (a) Two queues
// (b) One queue

struct StackTwoQueues {
    queue<int> q1, q2;

    void push(int val) {
        q2.push(val);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty.\n";
            return;
        }
        q1.pop();
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

struct StackOneQueue {
    queue<int> q;

    void push(int val) {
        int size = q.size();
        q.push(val);
        for (int i = 0; i < size; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty.\n";
            return;
        }
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    cout << "--- Stack implemented using TWO queues ---\n";
    StackTwoQueues s2;
    s2.push(1);
    s2.push(2);
    s2.push(3);
    cout << "Top: " << s2.top() << endl; // 3
    s2.pop();
    cout << "Top after pop: " << s2.top() << endl; // 2

    cout << "\n--- Stack implemented using ONE queue ---\n";
    StackOneQueue s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout << "Top: " << s1.top() << endl; // 30
    s1.pop();
    cout << "Top after pop: " << s1.top() << endl; // 20

    return 0;
}
