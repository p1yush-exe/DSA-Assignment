#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

void append(Node*& head, int val) {
    Node* node = new Node(val);
    if (!head) {
        head = node;
        return;
    }
    Node* p = head;
    while (p->next) p = p->next;
    p->next = node;
}

bool isCircular(Node* head) {
    if (!head) return false;
    Node* p = head->next;
    while (p && p != head) p = p->next;
    return p == head;
}

void makeCircular(Node* head) {
    if (!head) return;
    Node* p = head;
    while (p->next) p = p->next;
    p->next = head;
}

void freeListPossiblyCircular(Node*& head) {
    if (!head) return;
    if (!isCircular(head)) {
        Node* p = head;
        while (p) {
            Node* t = p->next;
            delete p;
            p = t;
        }
        head = nullptr;
        return;
    }
    Node* p = head->next;
    while (p != head) {
        Node* t = p->next;
        delete p;
        p = t;
    }
    delete head;
    head = nullptr;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    Node* head = nullptr;
    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        append(head, x);
    }
    int choice;
    cout << "Make the list circular? (1 = yes, 0 = no): ";
    cin >> choice;
    if (choice == 1) makeCircular(head);
    if (isCircular(head)) cout << "The linked list is circular\n";
    else cout << "The linked list is not circular\n";
    freeListPossiblyCircular(head);
    return 0;
}
