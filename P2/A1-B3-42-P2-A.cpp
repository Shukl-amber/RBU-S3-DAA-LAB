#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(void)
{
    int size;

    cout << "Enter Number of Frekles on Back: ";
    cin >> size;

    vector<vector<int>> Graph(size, vector<int>(size, -1));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
                continue;
            else if (Graph[j][i] != -1)
                Graph[i][j] = Graph[j][i];
            else
            {
                cout << "Enter Distance of Frekle " << i << " to Frekle " << j << ": ";
                cin >> Graph[i][j];
            }
        }
    }

    cout << "\n\nThe adjacency matrix of the graph is:\n"
         << endl;
    ;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (Graph[i][j] == -1)
                Graph[i][j] = 0;

            cout << Graph[i][j] << "   ";
        }
        cout << endl;
    }
    cout << "\n\n";

    vector<int> near(size, 0);
    vector<pair<int, int>> MCST(size - 1);

    int min = INT_MAX;
    int u = 0, v = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            int weight = std::min(Graph[i][j], Graph[j][i]);
            if (weight && weight < min)
            {
                min = weight;
                u = i;
                v = j;
            }
        }
    }

    cout << "First Selected Edge: " << u << " - " << v << endl;

    MCST[0] = {v, u};

    for (int i = 0; i < size; i++)
    {
        if (i != u && i != v) {
            int weight_u = Graph[i][u] > 0 ? Graph[i][u] : INT_MAX;
            int weight_v = Graph[i][v] > 0 ? Graph[i][v] : INT_MAX;
            near[i] = (weight_u < weight_v) ? u : v;
        }
    }

    near[u] = near[v] = -1;

    cout << "Near Array after first edge selection: " << endl;
    for (int l = 0; l < near.size(); l++) {
        cout << near[l] << " ";
    }
    cout << "\n\n";

    for (int i = 1; i < size - 1; i++)
    {
        min = INT_MAX;
        int k;

        for (int j = 0; j < size; j++)
        {
            if (near[j] != -1)
            {
                int weight = std::min(Graph[j][near[j]], Graph[near[j]][j]);
                if (weight && weight < min)
                {
                    min = weight;
                    k = j;
                }
            }
        }

        cout << "\nSelected Edge " << i << ": " << near[k] << " - " << endl;

        MCST[i] = {near[k], k};
        near[k] = -1;

        for (int j = 0; j < size; j++)
        {
            if (near[j] != -1)
            {
                int curr_weight = Graph[j][near[j]] > 0 ? Graph[j][near[j]] : INT_MAX;
                int new_weight = Graph[j][k] > 0 ? Graph[j][k] : INT_MAX;
                if (new_weight < curr_weight)
                {
                    near[j] = k;
                }
            }
        }

        cout << "Near Array after iteration " << i << ": " << endl;

        for (int l = 0; l < near.size(); l++)
        {
            cout << near[l] << " ";
        }
        cout << "\n\n";
    }

    int totalWeight = 0;

    cout << "Edge \tWeight\n";
    for (int i = 0; i < size - 1; i++)
    {
        cout << MCST[i].first << " - " << MCST[i].second << "\t"
             << Graph[MCST[i].first][MCST[i].second] << "\n";
        totalWeight += Graph[MCST[i].first][MCST[i].second];
    }
    cout << "Total Weight of Minimum Spanning Tree: " << totalWeight << "\n";
}