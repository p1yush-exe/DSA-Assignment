#include <iostream>
#include <algorithm>
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

Node* findMin(Node* root) {
    if (!root) return nullptr;
    Node* curr = root;
    while (curr->left) curr = curr->left;
    return curr;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        } else if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* succ = findMin(root->right);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
    }
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + max(lh, rh);
}

int minDepth(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    Node* root = nullptr;
    int choice;
    do {
        cout << "\n1. Insert element\n";
        cout << "2. Delete element\n";
        cout << "3. Display in-order\n";
        cout << "4. Maximum depth\n";
        cout << "5. Minimum depth\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        int val;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                root = insertNode(root, val);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                root = deleteNode(root, val);
                break;
            case 3:
                inorderPrint(root);
                cout << "\n";
                break;
            case 4:
                cout << "Maximum depth: " << maxDepth(root) << "\n";
                break;
            case 5:
                cout << "Minimum depth: " << minDepth(root) << "\n";
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 0);
    return 0;
}
