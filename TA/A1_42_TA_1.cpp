#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
    int from, to, weight;
};

int n, m;
vector<Edge> edges;
vector<long long> dist;
vector<int> parent;

void bellmanFord(int source) {
    dist.assign(n + 1, INT_MAX);
    parent.assign(n + 1, -1);
    dist[source] = 0;
    
    for (int i = 0; i < n - 1; i++)
        for (auto edge : edges)
            if (dist[edge.from] != INT_MAX && dist[edge.from] + edge.weight < dist[edge.to]) {
                dist[edge.to] = dist[edge.from] + edge.weight;
                parent[edge.to] = edge.from;
            }
    
    int cycleNode = -1;

    for (auto edge : edges)
        if (dist[edge.from] != INT_MAX && dist[edge.from] + edge.weight < dist[edge.to]) {
            dist[edge.to] = dist[edge.from] + edge.weight;
            parent[edge.to] = edge.from;
            cycleNode = edge.to;
        }
    
    if (cycleNode == -1) {
        cout << "No negative cycle" << endl;
        return;
    }
    
    int current = cycleNode;
    for (int i = 0; i < n; i++)
        current = parent[current];
    
    vector<int> cycle;
    int start = current;
    do {
        cycle.push_back(current);
        current = parent[current];
    } while (current != start);
    cycle.push_back(start);
    
    cout << "Negative cycle found: ";
    for (int i = cycle.size() - 1; i >= 0; i--) {
        cout << cycle[i];
        if (i > 0) cout << " ";
    }
    cout << endl;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    int source;
    cin >> source;
    bellmanFord(source);
    return 0;
}
