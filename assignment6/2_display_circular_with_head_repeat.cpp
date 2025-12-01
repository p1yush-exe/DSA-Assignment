#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
    CNode(int v) : data(v), next(nullptr) {}
};

void append(CNode*& head, int val) {
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

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    CNode* head = nullptr;
    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        append(head, x);
    }
    if (!head) {
        cout << "List is empty\n";
        return 0;
    }
    CNode* p = head;
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << head->data << "\n";
    CNode* q = head->next;
    while (q != head) {
        CNode* t = q->next;
        delete q;
        q = t;
    }
    delete head;
    return 0;
}
