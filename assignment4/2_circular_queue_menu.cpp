#include <iostream>
using namespace std;

// 2) Menu-driven program for Circular Queue using array
#define CAP 10

int cqArr[CAP];
int frontIdx = -1, rearIdx = -1;

bool isFullC() {
    return ((rearIdx + 1) % CAP == frontIdx);
}

bool isEmptyC() {
    return (frontIdx == -1);
}

void enqueueC(int val) {
    if (isFullC()) {
        cout << "\nCircular Queue is FULL\n";
        return;
    }
    if (frontIdx == -1) frontIdx = 0;
    rearIdx = (rearIdx + 1) % CAP;
    cqArr[rearIdx] = val;
    cout << "Enqueued " << val << " into circular queue.\n";
}

void dequeueC() {
    if (isEmptyC()) {
        cout << "\nCircular Queue is EMPTY\n";
        return;
    }
    cout << "Dequeued: " << cqArr[frontIdx] << "\n";
    if (frontIdx == rearIdx) {
        // only one element
        frontIdx = rearIdx = -1;
    } else {
        frontIdx = (frontIdx + 1) % CAP;
    }
}

void displayC() {
    if (isEmptyC()) {
        cout << "\nCircular Queue is EMPTY\n";
        return;
    }
    cout << "\nCircular Queue elements (front to rear): ";
    int i = frontIdx;
    while (true) {
        cout << cqArr[i] << " ";
        if (i == rearIdx) break;
        i = (i + 1) % CAP;
    }
    cout << "\n";
}

void peekC() {
    if (isEmptyC()) {
        cout << "\nCircular Queue is EMPTY\n";
        return;
    }
    cout << "\nFront element is: " << cqArr[frontIdx] << "\n";
}

int main() {
    int ch, val;
    do {
        cout << "\n--- CIRCULAR QUEUE MENU (Array) ---\n";
        cout << "1. enqueue()\n";
        cout << "2. dequeue()\n";
        cout << "3. isEmpty()\n";
        cout << "4. isFull()\n";
        cout << "5. display()\n";
        cout << "6. peek()\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> val;
            enqueueC(val);
            break;
        case 2:
            dequeueC();
            break;
        case 3:
            if (isEmptyC()) cout << "Circular Queue is EMPTY.\n";
            else cout << "Circular Queue is NOT empty.\n";
            break;
        case 4:
            if (isFullC()) cout << "Circular Queue is FULL.\n";
            else cout << "Circular Queue is NOT full.\n";
            break;
        case 5:
            displayC();
            break;
        case 6:
            peekC();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (ch != 0);

    return 0;
}
