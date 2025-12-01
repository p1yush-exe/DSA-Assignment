#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

bool isBSTUtil(Node* root, long long minVal, long long maxVal) {
    if (!root) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBSTUtil(root->left, minVal, root->data) && isBSTUtil(root->right, root->data, maxVal);
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    if (n <= 0) {
        cout << "Empty tree\n";
        return 0;
    }
    vector<Node*> nodes(n, nullptr);
    cout << "Enter " << n << " node values:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nodes[i] = new Node(x);
    }
    cout << "For each node from 0 to " << n - 1 << " enter indices of left and right child (-1 for null):\n";
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        if (l != -1) nodes[i]->left = nodes[l];
        if (r != -1) nodes[i]->right = nodes[r];
    }
    Node* root = nodes[0];
    if (isBSTUtil(root, LLONG_MIN, LLONG_MAX)) cout << "The tree is a BST\n";
    else cout << "The tree is not a BST\n";
    for (int i = 0; i < n; i++) delete nodes[i];
    return 0;
}
