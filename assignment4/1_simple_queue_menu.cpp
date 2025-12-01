#include <iostream>
using namespace std;

// 1) Menu-driven program for Simple Queue using array
#define CAP 10

int qArr[CAP];
int frontIdx = -1, rearIdx = -1;

bool isFull() {
    return rearIdx == CAP - 1;
}

bool isEmpty() {
    return frontIdx == -1;
}

void enqueue(int val) {
    if (isFull()) {
        cout << "\nQueue is FULL (Overflow)\n";
        return;
    }
    if (frontIdx == -1) frontIdx = 0;
    rearIdx++;
    qArr[rearIdx] = val;
    cout << "Enqueued " << val << " into the queue.\n";
}

void dequeue() {
    if (isEmpty() || frontIdx > rearIdx) {
        cout << "\nQueue is EMPTY (Underflow)\n";
        frontIdx = rearIdx = -1; // reset
        return;
    }
    cout << "Dequeued: " << qArr[frontIdx] << "\n";
    frontIdx++;
    if (frontIdx > rearIdx) {
        frontIdx = rearIdx = -1;
    }
}

void display() {
    if (isEmpty()) {
        cout << "\nQueue is EMPTY\n";
        return;
    }
    cout << "\nQueue elements (front to rear): ";
    for (int i = frontIdx; i <= rearIdx; i++) {
        cout << qArr[i] << " ";
    }
    cout << "\n";
}

void peek() {
    if (isEmpty()) {
        cout << "\nQueue is EMPTY\n";
        return;
    }
    cout << "\nFront element is: " << qArr[frontIdx] << "\n";
}

int main() {
    int ch, val;
    do {
        cout << "\n--- SIMPLE QUEUE MENU (Array) ---\n";
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
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            if (isEmpty()) cout << "Queue is EMPTY.\n";
            else cout << "Queue is NOT empty.\n";
            break;
        case 4:
            if (isFull()) cout << "Queue is FULL.\n";
            else cout << "Queue is NOT full.\n";
            break;
        case 5:
            display();
            break;
        case 6:
            peek();
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
