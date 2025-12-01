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

Node* findMiddle(Node* head) {
    if (!head) return nullptr;

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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

    cout << "Linked list: ";
    display(head);

    Node* mid = findMiddle(head);
    if (mid) {
        cout << "Middle element: " << mid->data << "\n";
    } else {
        cout << "List is empty, no middle element.\n";
    }

    freeList(head);
    return 0;
}
