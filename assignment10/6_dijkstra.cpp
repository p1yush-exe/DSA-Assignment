#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct Edge {
    int to;
    int w;
};

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    vector<vector<Edge>> adj(n);
    cout << "Enter directed weighted edges (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u < 0 || u >= n || v < 0 || v >= n) continue;
        adj[u].push_back({v, w});
    }
    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    if (src < 0 || src >= n) {
        cout << "Invalid source\n";
        return 0;
    }
    vector<int> dist(n, numeric_limits<int>::max());
    dist[src] = 0;
    using P = pair<int,int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto& e : adj[u]) {
            int v = e.to;
            int w = e.w;
            if (dist[u] != numeric_limits<int>::max() && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == numeric_limits<int>::max()) cout << i << ": INF\n";
        else cout << i << ": " << dist[i] << "\n";
    }
    return 0;
}
