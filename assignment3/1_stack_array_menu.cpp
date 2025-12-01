#include <iostream>

using namespace std;

#define CAP 100

int stkArr[CAP];
int top = -1;

bool isFull() { return top == CAP - 1; }
bool isEmpty() { return top == -1; }

void push(int val) {
    if (isFull()) {
        cout << "\nStack Overflow\n";
        return;
    }
    top++;
    stkArr[top] = val;
    cout << "Pushed " << val << " onto the stack.\n";
}

void pop() {
    if (isEmpty()) {
        cout << "\nStack Underflow\n";
        return;
    }
    cout << "\nPopped: " << stkArr[top] << "\n";
    top--;
}

void display() {
    if (isEmpty()) {
        cout << "\nStack is Empty\n";
        return;
    }
    cout << "\nStack (top to bottom): ";
    for (int i = top; i >= 0; i--) {
        cout << stkArr[i] << " ";
    }
    cout << "\n";
}

void peek() {
    if (isEmpty()) {
        cout << "\nStack is Empty\n";
        return;
    }
    cout << "\nTop element is: " << stkArr[top] << "\n";
}

int main() {
    int ch, val;
    do {
        cout << "\n--- STACK MENU (Array Implementation) ---\n";
        cout << "1. push()\n";
        cout << "2. pop()\n";
        cout << "3. isEmpty()\n";
        cout << "4. isFull()\n";
        cout << "5. display()\n";
        cout << "6. peek()\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter value to push: ";
            cin >> val;
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            if (isEmpty()) cout << "Stack is empty.\n";
            else cout << "Stack is not empty.\n";
            break;
        case 4:
            if (isFull()) cout << "Stack is full.\n";
            else cout << "Stack is not full.\n";
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
