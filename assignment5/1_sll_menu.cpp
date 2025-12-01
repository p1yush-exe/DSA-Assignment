#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* head = nullptr;

void insertAtBeginning(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << val << " at the beginning.\n";
}

void insertAtEnd(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        cout << "Inserted " << val << " as the first node.\n";
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    cout << "Inserted " << val << " at the end.\n";
}

bool findNode(int key, Node*& prev, Node*& curr) {
    prev = nullptr;
    curr = head;
    while (curr != nullptr && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }
    return (curr != nullptr);
}

void insertBeforeValue(int key, int val) {
    if (head == nullptr) {
        cout << "List is empty. Cannot insert before " << key << ".\n";
        return;
    }

    if (head->data == key) {
        insertAtBeginning(val);
        return;
    }

    Node* prev = nullptr;
    Node* curr = nullptr;
    if (!findNode(key, prev, curr)) {
        cout << "Value " << key << " not found in the list.\n";
        return;
    }

    Node* newNode = new Node(val);
    prev->next = newNode;
    newNode->next = curr;
    cout << "Inserted " << val << " before " << key << ".\n";
}

void insertAfterValue(int key, int val) {
    if (head == nullptr) {
        cout << "List is empty. Cannot insert after " << key << ".\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Value " << key << " not found in the list.\n";
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Inserted " << val << " after " << key << ".\n";
}

void deleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is already empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted node with value " << temp->data << " from beginning.\n";
    delete temp;
}

void deleteFromEnd() {
    if (head == nullptr) {
        cout << "List is already empty.\n";
        return;
    }
    if (head->next == nullptr) {
        cout << "Deleted last node with value " << head->data << ".\n";
        delete head;
        head = nullptr;
        return;
    }
    Node* prev = nullptr;
    Node* temp = head;
    while (temp->next != nullptr) {
        prev = temp;
        temp = temp->next;
    }
    cout << "Deleted node with value " << temp->data << " from end.\n";
    prev->next = nullptr;
    delete temp;
}

void deleteValue(int key) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        cout << "Deleted node with value " << key << ".\n";
        delete temp;
        return;
    }
    Node* prev = nullptr;
    Node* curr = nullptr;
    if (!findNode(key, prev, curr)) {
        cout << "Value " << key << " not found in the list.\n";
        return;
    }
    prev->next = curr->next;
    cout << "Deleted node with value " << key << ".\n";
    delete curr;
}

void searchValue(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != nullptr) {
        if (temp->data == key) {
            cout << "Value " << key << " found at position " << pos << " from head.\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Value " << key << " not found in the list.\n";
}

void displayList() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    cout << "List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

void freeList() {
    Node* temp = head;
    while (temp != nullptr) {
        Node* nxt = temp->next;
        delete temp;
        temp = nxt;
    }
    head = nullptr;
}

int main() {
    int choice, val, key;
    do {
        cout << "\n--- SINGLY LINKED LIST MENU ---\n";
        cout << "1. Insertion at the beginning\n";
        cout << "2. Insertion at the end\n";
        cout << "3. Insertion BEFORE a node (by value)\n";
        cout << "4. Insertion AFTER a node (by value)\n";
        cout << "5. Deletion from the beginning\n";
        cout << "6. Deletion from the end\n";
        cout << "7. Deletion of a specific node (by value)\n";
        cout << "8. Search for a node (by value)\n";
        cout << "9. Display all node values\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> val;
            insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value to insert at end: ";
            cin >> val;
            insertAtEnd(val);
            break;
        case 3:
            cout << "Enter the existing node value (key): ";
            cin >> key;
            cout << "Enter new value to insert BEFORE " << key << ": ";
            cin >> val;
            insertBeforeValue(key, val);
            break;
        case 4:
            cout << "Enter the existing node value (key): ";
            cin >> key;
            cout << "Enter new value to insert AFTER " << key << ": ";
            cin >> val;
            insertAfterValue(key, val);
            break;
        case 5:
            deleteFromBeginning();
            break;
        case 6:
            deleteFromEnd();
            break;
        case 7:
            cout << "Enter value to delete: ";
            cin >> key;
            deleteValue(key);
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> key;
            searchValue(key);
            break;
        case 9:
            displayList();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    freeList();
    return 0;
}
