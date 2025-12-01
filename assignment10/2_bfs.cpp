#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    vector<vector<int>> adj(n);
    cout << "Enter " << m << " edges (u v) for undirected graph:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u < 0 || u >= n || v < 0 || v >= n) continue;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start;
    cout << "Enter start vertex for BFS: ";
    cin >> start;
    if (start < 0 || start >= n) {
        cout << "Invalid start\n";
        return 0;
    }
    vector<bool> vis(n, false);
    queue<int> q;
    vis[start] = true;
    q.push(start);
    cout << "BFS order: ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    cout << "\n";
    return 0;
}
