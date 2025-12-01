#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int findParent(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    parent[x] = findParent(parent[x], parent);
    return parent[x];
}

void unionSet(int a, int b, vector<int>& parent, vector<int>& rnk) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a != b) {
        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
    }
}

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    vector<Edge> edges(m);
    cout << "Enter edges (u v w) for undirected graph:\n";
    for (int i = 0; i < m; i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) { return a.w < b.w; });
    vector<int> parent(n), rnk(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;
    vector<Edge> mst;
    int totalWeight = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);
        if (pu != pv) {
            unionSet(pu, pv, parent, rnk);
            mst.push_back(edges[i]);
            totalWeight += w;
        }
    }
    cout << "Edges in MST:\n";
    for (auto& e : mst) cout << e.u << " - " << e.v << " : " << e.w << "\n";
    cout << "Total weight: " << totalWeight << "\n";
    return 0;
}
