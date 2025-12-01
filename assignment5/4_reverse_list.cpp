#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void append(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

void reverseList(Node*& head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* nxt = nullptr;

    while (curr != nullptr) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;
}

void freeList(Node*& head) {
    Node* temp = head;
    while (temp) {
        Node* nxt = temp->next;
        delete temp;
        temp = nxt;
    }
    head = nullptr;
}

int main() {
    Node* head = nullptr;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        append(head, x);
    }

    cout << "Original list: ";
    display(head);

    reverseList(head);

    cout << "Reversed list: ";
    display(head);

    freeList(head);
    return 0;
}
