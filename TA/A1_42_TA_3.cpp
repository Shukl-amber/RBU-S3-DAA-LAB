#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge
{
    int from, to, delay;
};

int n, m;
vector<Edge> edges;
vector<int> dist;
vector<string> routerName;

void bellmanFord(int source)
{
    dist[source] = 0;

    for (int i = 0; i < n - 1; i++)
        for (auto edge : edges)
            if (dist[edge.from] != INT_MAX && dist[edge.from] + edge.delay < dist[edge.to])
                dist[edge.to] = dist[edge.from] + edge.delay;

    for (int i = 0; i < n; i++)
    {
        if (i == source)
            continue;
        cout << routerName[i] << " = ";
        if (dist[i] == INT_MAX)
            cout << "Unreachable" << endl;
        else
            cout << dist[i] << endl;
    }

    double density = (double)m / (n * (n - 1)) * 100;
    cout << "\nDensity: " << fixed << setprecision(1) << density << "%";
    if (density < 30)
        cout << " (Sparse - List better)" << endl;
    else if (density < 60)
        cout << " (Medium)" << endl;
    else
        cout << " (Dense - Matrix better)" << endl;
}

int main()
{
    cin >> n;
    routerName.resize(n);
    for (int i = 0; i < n; i++)
        cin >> routerName[i];

    dist.resize(n, INT_MAX);

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int from, to, delay;
        cin >> from >> to >> delay;
        edges.push_back({from, to, delay});
    }

    int source;
    cin >> source;
    bellmanFord(source);
    return 0;
}
