#include <bits/stdc++.h>
using namespace std;
typedef double db;

vector<db> keys, hit_prob, miss_prob;
int n;

db computeOBST()
{
    vector<vector<db>> e(n + 1, vector<db>(n + 1, 0.0));
    vector<vector<db>> w(n + 1, vector<db>(n + 1, 0.0));

    for (int i = 0; i <= n; i++) // Fill Diagonals
    {
        e[i][i] = miss_prob[i];
        w[i][i] = miss_prob[i];
    }

    for (int len = 1; len <= n; len++)
    {
        int j;
        for (int i = 0; i + len <= n; i++)
        {
            j = i + len;
            e[i][j] = INT_MAX;
            w[i][j] = w[i][j - 1] + hit_prob[j - 1] + miss_prob[j];

            for (int r = i; r < j; r++)
            {
                db cost = e[i][r]       // Cost of left subtree [i, r) -> i to r-1
                          + e[r + 1][j] // Cost of right subtree [r+1, j) -> r+1 to j-1
                          + w[i][j];    // Total weight of current subtree

                e[i][j] = min(e[i][j], cost);
            }
        }
    }

    return e[0][n];
}

int main()
{
    cout << "Enter N: ";
    cin >> n;

    keys.resize(n);
    hit_prob.resize(n);
    miss_prob.resize(n + 1);

    cout << "Enter Keys: ";
    for (int i = 0; i < n; i++)
        cin >> keys[i];

    cout << "Enter P[] Array: ";
    for (int i = 0; i < n; i++)
        cin >> hit_prob[i];

    cout << "Enter Q[] Array: ";
    for (int i = 0; i <= n; i++)
        cin >> miss_prob[i];

    db minCost = computeOBST();

    cout << setprecision(4) << minCost << '\n';

    return 0;
}
