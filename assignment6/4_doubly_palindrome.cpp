#include <iostream>
#include <string>
using namespace std;

struct DNode {
    char data;
    DNode* prev;
    DNode* next;
    DNode(char v) : data(v), prev(nullptr), next(nullptr) {}
};

void append(DNode*& head, DNode*& tail, char ch) {
    DNode* node = new DNode(ch);
    if (!head) {
        head = tail = node;
        return;
    }
    tail->next = node;
    node->prev = tail;
    tail = node;
}

void freeList(DNode*& head) {
    DNode* p = head;
    while (p) {
        DNode* t = p->next;
        delete p;
        p = t;
    }
    head = nullptr;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    DNode* head = nullptr;
    DNode* tail = nullptr;
    for (char c : s) {
        if (c == ' ') continue;
        append(head, tail, c);
    }
    if (!head) {
        cout << "Empty list\n";
        return 0;
    }
    DNode* left = head;
    DNode* right = tail;
    bool ok = true;
    while (left != right && right->next != left) {
        if (left->data != right->data) {
            ok = false;
            break;
        }
        left = left->next;
        right = right->prev;
    }
    if (ok && left->data != right->data) ok = false;
    if (ok) cout << "Palindrome\n";
    else cout << "Not palindrome\n";
    freeList(head);
    return 0;
}
