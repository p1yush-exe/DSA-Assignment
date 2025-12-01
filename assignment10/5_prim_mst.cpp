#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    vector<vector<int>> w(n, vector<int>(n));
    cout << "Enter adjacency matrix (0 for no edge, positive weight otherwise):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j];
    vector<bool> inMST(n, false);
    vector<int> key(n, numeric_limits<int>::max());
    vector<int> parent(n, -1);
    key[0] = 0;
    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        int minKey = numeric_limits<int>::max();
        for (int v = 0; v < n; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }
        if (u == -1) break;
        inMST[u] = true;
        for (int v = 0; v < n; v++) {
            if (w[u][v] && !inMST[v] && w[u][v] < key[v]) {
                key[v] = w[u][v];
                parent[v] = u;
            }
        }
    }
    cout << "Edges in MST:\n";
    int totalWeight = 0;
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << " : " << w[parent[i]][i] << "\n";
            totalWeight += w[parent[i]][i];
        }
    }
    cout << "Total weight: " << totalWeight << "\n";
    return 0;
}
