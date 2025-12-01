#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
    CNode(int v) : data(v), next(nullptr) {}
};

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int v) : data(v), prev(nullptr), next(nullptr) {}
};

CNode* chead = nullptr;
DNode* dhead = nullptr;

void displayCircular() {
    if (!chead) {
        cout << "List is empty\n";
        return;
    }
    CNode* p = chead;
    do {
        cout << p->data;
        p = p->next;
        if (p != chead) cout << " -> ";
    } while (p != chead);
    cout << " -> (back to head)\n";
}

void insertCircularBeginning(int val) {
    CNode* node = new CNode(val);
    if (!chead) {
        chead = node;
        node->next = node;
        return;
    }
    CNode* tail = chead;
    while (tail->next != chead) tail = tail->next;
    node->next = chead;
    chead = node;
    tail->next = chead;
}

void insertCircularEnd(int val) {
    CNode* node = new CNode(val);
    if (!chead) {
        chead = node;
        node->next = node;
        return;
    }
    CNode* tail = chead;
    while (tail->next != chead) tail = tail->next;
    tail->next = node;
    node->next = chead;
}

CNode* findCircular(int key) {
    if (!chead) return nullptr;
    CNode* p = chead;
    do {
        if (p->data == key) return p;
        p = p->next;
    } while (p != chead);
    return nullptr;
}

void insertCircularAfter(int key, int val) {
    CNode* pos = findCircular(key);
    if (!pos) {
        cout << "Key not found\n";
        return;
    }
    CNode* node = new CNode(val);
    node->next = pos->next;
    pos->next = node;
}

void insertCircularBefore(int key, int val) {
    if (!chead) {
        cout << "List is empty\n";
        return;
    }
    if (chead->data == key) {
        insertCircularBeginning(val);
        return;
    }
    CNode* prev = chead;
    CNode* curr = chead->next;
    while (curr != chead && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == chead) {
        cout << "Key not found\n";
        return;
    }
    CNode* node = new CNode(val);
    prev->next = node;
    node->next = curr;
}

void deleteCircularValue(int key) {
    if (!chead) {
        cout << "List is empty\n";
        return;
    }
    CNode* curr = chead;
    CNode* prev = nullptr;
    do {
        if (curr->data == key) break;
        prev = curr;
        curr = curr->next;
    } while (curr != chead);
    if (curr->data != key) {
        cout << "Key not found\n";
        return;
    }
    if (curr == chead && curr->next == chead) {
        delete curr;
        chead = nullptr;
        return;
    }
    if (curr == chead) {
        CNode* tail = chead;
        while (tail->next != chead) tail = tail->next;
        chead = chead->next;
        tail->next = chead;
        delete curr;
        return;
    }
    prev->next = curr->next;
    delete curr;
}

void searchCircular(int key) {
    if (!chead) {
        cout << "List is empty\n";
        return;
    }
    int pos = 1;
    CNode* p = chead;
    do {
        if (p->data == key) {
            cout << "Found at position " << pos << " from head\n";
            return;
        }
        p = p->next;
        pos++;
    } while (p != chead);
    cout << "Not found\n";
}

void freeCircular() {
    if (!chead) return;
    CNode* p = chead->next;
    while (p != chead) {
        CNode* t = p->next;
        delete p;
        p = t;
    }
    delete chead;
    chead = nullptr;
}

void displayDoubly() {
    if (!dhead) {
        cout << "List is empty\n";
        return;
    }
    DNode* p = dhead;
    while (p) {
        cout << p->data;
        if (p->next) cout << " <-> ";
        p = p->next;
    }
    cout << " -> NULL\n";
}

void insertDoublyBeginning(int val) {
    DNode* node = new DNode(val);
    if (!dhead) {
        dhead = node;
        return;
    }
    node->next = dhead;
    dhead->prev = node;
    dhead = node;
}

void insertDoublyEnd(int val) {
    DNode* node = new DNode(val);
    if (!dhead) {
        dhead = node;
        return;
    }
    DNode* p = dhead;
    while (p->next) p = p->next;
    p->next = node;
    node->prev = p;
}

DNode* findDoubly(int key) {
    DNode* p = dhead;
    while (p) {
        if (p->data == key) return p;
        p = p->next;
    }
    return nullptr;
}

void insertDoublyAfter(int key, int val) {
    DNode* pos = findDoubly(key);
    if (!pos) {
        cout << "Key not found\n";
        return;
    }
    DNode* node = new DNode(val);
    node->next = pos->next;
    node->prev = pos;
    if (pos->next) pos->next->prev = node;
    pos->next = node;
}

void insertDoublyBefore(int key, int val) {
    DNode* pos = findDoubly(key);
    if (!pos) {
        cout << "Key not found\n";
        return;
    }
    if (pos == dhead) {
        insertDoublyBeginning(val);
        return;
    }
    DNode* node = new DNode(val);
    node->next = pos;
    node->prev = pos->prev;
    pos->prev->next = node;
    pos->prev = node;
}

void deleteDoublyValue(int key) {
    if (!dhead) {
        cout << "List is empty\n";
        return;
    }
    DNode* p = findDoubly(key);
    if (!p) {
        cout << "Key not found\n";
        return;
    }
    if (p == dhead) {
        dhead = dhead->next;
        if (dhead) dhead->prev = nullptr;
        delete p;
        return;
    }
    if (p->next) p->next->prev = p->prev;
    if (p->prev) p->prev->next = p->next;
    delete p;
}

void searchDoubly(int key) {
    int pos = 1;
    DNode* p = dhead;
    while (p) {
        if (p->data == key) {
            cout << "Found at position " << pos << " from head\n";
            return;
        }
        p = p->next;
        pos++;
    }
    cout << "Not found\n";
}

void freeDoubly() {
    DNode* p = dhead;
    while (p) {
        DNode* t = p->next;
        delete p;
        p = t;
    }
    dhead = nullptr;
}

int main() {
    int mainChoice;
    do {
        cout << "\n1. Operate on Circular Linked List\n";
        cout << "2. Operate on Doubly Linked List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;
        if (mainChoice == 1) {
            int ch;
            do {
                cout << "\n--- Circular Linked List Menu ---\n";
                cout << "1. Insert at beginning\n";
                cout << "2. Insert at end\n";
                cout << "3. Insert before a value\n";
                cout << "4. Insert after a value\n";
                cout << "5. Delete a specific node\n";
                cout << "6. Search for a node\n";
                cout << "7. Display list\n";
                cout << "0. Back to main menu\n";
                cout << "Enter your choice: ";
                cin >> ch;
                int val, key;
                switch (ch) {
                    case 1:
                        cout << "Enter value: ";
                        cin >> val;
                        insertCircularBeginning(val);
                        break;
                    case 2:
                        cout << "Enter value: ";
                        cin >> val;
                        insertCircularEnd(val);
                        break;
                    case 3:
                        cout << "Enter key: ";
                        cin >> key;
                        cout << "Enter value to insert before " << key << ": ";
                        cin >> val;
                        insertCircularBefore(key, val);
                        break;
                    case 4:
                        cout << "Enter key: ";
                        cin >> key;
                        cout << "Enter value to insert after " << key << ": ";
                        cin >> val;
                        insertCircularAfter(key, val);
                        break;
                    case 5:
                        cout << "Enter value to delete: ";
                        cin >> key;
                        deleteCircularValue(key);
                        break;
                    case 6:
                        cout << "Enter value to search: ";
                        cin >> key;
                        searchCircular(key);
                        break;
                    case 7:
                        displayCircular();
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Invalid choice\n";
                }
            } while (ch != 0);
        } else if (mainChoice == 2) {
            int ch;
            do {
                cout << "\n--- Doubly Linked List Menu ---\n";
                cout << "1. Insert at beginning\n";
                cout << "2. Insert at end\n";
                cout << "3. Insert before a value\n";
                cout << "4. Insert after a value\n";
                cout << "5. Delete a specific node\n";
                cout << "6. Search for a node\n";
                cout << "7. Display list\n";
                cout << "0. Back to main menu\n";
                cout << "Enter your choice: ";
                cin >> ch;
                int val, key;
                switch (ch) {
                    case 1:
                        cout << "Enter value: ";
                        cin >> val;
                        insertDoublyBeginning(val);
                        break;
                    case 2:
                        cout << "Enter value: ";
                        cin >> val;
                        insertDoublyEnd(val);
                        break;
                    case 3:
                        cout << "Enter key: ";
                        cin >> key;
                        cout << "Enter value to insert before " << key << ": ";
                        cin >> val;
                        insertDoublyBefore(key, val);
                        break;
                    case 4:
                        cout << "Enter key: ";
                        cin >> key;
                        cout << "Enter value to insert after " << key << ": ";
                        cin >> val;
                        insertDoublyAfter(key, val);
                        break;
                    case 5:
                        cout << "Enter value to delete: ";
                        cin >> key;
                        deleteDoublyValue(key);
                        break;
                    case 6:
                        cout << "Enter value to search: ";
                        cin >> key;
                        searchDoubly(key);
                        break;
                    case 7:
                        displayDoubly();
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Invalid choice\n";
                }
            } while (ch != 0);
        }
    } while (mainChoice != 0);
    freeCircular();
    freeDoubly();
    return 0;
}
