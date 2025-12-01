#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int v) : data(v), prev(nullptr), next(nullptr) {}
};

struct CNode {
    int data;
    CNode* next;
    CNode(int v) : data(v), next(nullptr) {}
};

void appendD(DNode*& head, int val) {
    DNode* node = new DNode(val);
    if (!head) {
        head = node;
        return;
    }
    DNode* p = head;
    while (p->next) p = p->next;
    p->next = node;
    node->prev = p;
}

void appendC(CNode*& head, int val) {
    CNode* node = new CNode(val);
    if (!head) {
        head = node;
        node->next = node;
        return;
    }
    CNode* tail = head;
    while (tail->next != head) tail = tail->next;
    tail->next = node;
    node->next = head;
}

int sizeD(DNode* head) {
    int c = 0;
    DNode* p = head;
    while (p) {
        c++;
        p = p->next;
    }
    return c;
}

int sizeC(CNode* head) {
    if (!head) return 0;
    int c = 0;
    CNode* p = head;
    do {
        c++;
        p = p->next;
    } while (p != head);
    return c;
}

void freeD(DNode*& head) {
    DNode* p = head;
    while (p) {
        DNode* t = p->next;
        delete p;
        p = t;
    }
    head = nullptr;
}

void freeC(CNode*& head) {
    if (!head) return;
    CNode* p = head->next;
    while (p != head) {
        CNode* t = p->next;
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
    DNode* dhead = nullptr;
    CNode* chead = nullptr;
    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        appendD(dhead, x);
        appendC(chead, x);
    }
    cout << "Size of Doubly Linked List: " << sizeD(dhead) << "\n";
    cout << "Size of Circular Linked List: " << sizeC(chead) << "\n";
    freeD(dhead);
    freeC(chead);
    return 0;
}
