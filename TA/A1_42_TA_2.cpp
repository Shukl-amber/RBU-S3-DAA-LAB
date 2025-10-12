#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<double> dist;
vector<int> parent;
vector<string> currencyName;

struct Edge
{
    int from, to;
    double weight;
};

vector<Edge> edges;

void detectArbitrage(int source)
{
    parent.assign(n, -1);
    dist[source] = 0;

    for (int i = 0; i < n - 1; i++)
        for (auto edge : edges)
            if (dist[edge.from] != INT_MAX && dist[edge.from] + edge.weight < dist[edge.to])
            {
                dist[edge.to] = dist[edge.from] + edge.weight;
                parent[edge.to] = edge.from;
            }

    int cycleNode = -1;
    for (auto edge : edges)
        if (dist[edge.from] != INT_MAX && dist[edge.from] + edge.weight < dist[edge.to])
        {
            dist[edge.to] = dist[edge.from] + edge.weight;
            parent[edge.to] = edge.from;
            cycleNode = edge.to;
            break;
        }

    if (cycleNode == -1)
    {
        cout << "No arbitrage opportunity" << endl;
        return;
    }

    int current = cycleNode;
    for (int i = 0; i < n; i++)
        current = parent[current];

    vector<int> cycle;
    int start = current;
    do
    {
        cycle.push_back(current);
        current = parent[current];
    } while (current != start);
    cycle.push_back(start);

    cout << "Arbitrage found: ";
    for (int i = cycle.size() - 1; i >= 0; i--)
    {
        cout << currencyName[cycle[i]];
        if (i > 0)
            cout << " -> ";
    }
    cout << endl;
}

int main()
{
    cin >> n;
    currencyName.resize(n);
    for (int i = 0; i < n; i++)
        cin >> currencyName[i];

    dist.resize(n, INT_MAX);

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int from, to;
        double rate;
        cin >> from >> to >> rate;
        double weight = -log(rate);
        edges.push_back({from, to, weight});
    }

    detectArbitrage(0);
    return 0;
}