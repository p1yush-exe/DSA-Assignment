#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insertNode(root->left, val);
    else if (val > root->data) root->right = insertNode(root->right, val);
    return root;
}

Node* searchRecursive(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

Node* searchIterative(Node* root, int key) {
    Node* curr = root;
    while (curr) {
        if (key == curr->data) return curr;
        if (key < curr->data) curr = curr->left;
        else curr = curr->right;
    }
    return nullptr;
}

Node* findMin(Node* root) {
    if (!root) return nullptr;
    Node* curr = root;
    while (curr->left) curr = curr->left;
    return curr;
}

Node* findMax(Node* root) {
    if (!root) return nullptr;
    Node* curr = root;
    while (curr->right) curr = curr->right;
    return curr;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* curr = root;
    Node* succ = nullptr;
    while (curr && curr->data != key) {
        if (key < curr->data) {
            succ = curr;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    if (!curr) return nullptr;
    if (curr->right) {
        return findMin(curr->right);
    }
    return succ;
}

Node* inorderPredecessor(Node* root, int key) {
    Node* curr = root;
    Node* pred = nullptr;
    while (curr && curr->data != key) {
        if (key > curr->data) {
            pred = curr;
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    if (!curr) return nullptr;
    if (curr->left) {
        return findMax(curr->left);
    }
    return pred;
}

void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    Node* root = nullptr;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insertNode(root, x);
    }
    int choice;
    do {
        cout << "\n1. Search (recursive)\n";
        cout << "2. Search (iterative)\n";
        cout << "3. Maximum element\n";
        cout << "4. Minimum element\n";
        cout << "5. In-order successor of a key\n";
        cout << "6. In-order predecessor of a key\n";
        cout << "7. Display in-order\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        int key;
        Node* res;
        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                res = searchRecursive(root, key);
                if (res) cout << "Found\n"; else cout << "Not found\n";
                break;
            case 2:
                cout << "Enter key: ";
                cin >> key;
                res = searchIterative(root, key);
                if (res) cout << "Found\n"; else cout << "Not found\n";
                break;
            case 3:
                res = findMax(root);
                if (res) cout << "Maximum: " << res->data << "\n"; else cout << "Tree empty\n";
                break;
            case 4:
                res = findMin(root);
                if (res) cout << "Minimum: " << res->data << "\n"; else cout << "Tree empty\n";
                break;
            case 5:
                cout << "Enter key: ";
                cin >> key;
                res = inorderSuccessor(root, key);
                if (res) cout << "Successor: " << res->data << "\n"; else cout << "No successor or key not found\n";
                break;
            case 6:
                cout << "Enter key: ";
                cin >> key;
                res = inorderPredecessor(root, key);
                if (res) cout << "Predecessor: " << res->data << "\n"; else cout << "No predecessor or key not found\n";
                break;
            case 7:
                inorderPrint(root);
                cout << "\n";
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 0);
    return 0;
}
