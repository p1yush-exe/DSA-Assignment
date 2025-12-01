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

int countAndDeleteKey(Node*& head, int key) {
    int count = 0;

    while (head && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node* curr = head;
    Node* prev = nullptr;

    while (curr) {
        if (curr->data == key) {
            prev->next = curr->next;
            Node* temp = curr;
            curr = curr->next;
            delete temp;
            count++;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return count;
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

    int key;
    cout << "Enter key to count and delete: ";
    cin >> key;

    int total = countAndDeleteKey(head, key);
    cout << "Total occurrences of " << key << ": " << total << "\n";

    cout << "List after deleting all occurrences: ";
    display(head);

    freeList(head);
    return 0;
}
