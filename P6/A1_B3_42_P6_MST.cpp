#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ll nodes, stages;
    cout << "Enter No of Stages: ";
    cin >> stages;
    cout << "Enter No of Nodes: ";
    cin >> nodes;

    vector<vector<ll>> arr(nodes, vector<ll>(nodes, INT_MAX));

    ll connections;
    cout << "Enter No Of Connections: ";
    cin >> connections;

    for (ll i = 0; i < connections; i++)
    {
        printf("\nConnection No %d From: To: And Cost: ", i + 1);
        int j, k;
        cin >> j >> k >> arr[j][k];
    }

    vector<ll> bcost(nodes, INT_MAX), prev(nodes, -1), path(nodes, -1);

    bcost[0] = 0;

    for (ll i = 1; i < nodes; i++)
    {
        for (ll j = 0; j < nodes; j++)
        {
            if (arr[j][i] != INT_MAX && bcost[j] != INT_MAX)
            {
                if (bcost[j] + arr[j][i] < bcost[i])
                    bcost[i] = bcost[j] + arr[j][i],
                    prev[i] = j;
            }
        }

        // printf("\nMinimum Cost For Node %d is %d\n with Prev as %d", i, bcost[i], prev[i]);
    }
    cout << endl;

    ll curr = nodes - 2;
    path[0] = 0;
    path[nodes - 1] = nodes - 1;

    for (ll i = nodes - 2; i > nodes - stages; i--)
        path[i] = prev[i + 1];

    cout << "Shortest Path is: ";

    for (ll i = nodes - stages; i < nodes; i++)
        cout << path[i] << " - ";

    cout << "With Minimum Cost = " << bcost[nodes - 1];

    return 0;
}