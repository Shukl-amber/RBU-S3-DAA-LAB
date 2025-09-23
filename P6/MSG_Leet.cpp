#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

        for (int j = 0; j < n; j++)
            dp[0][j] = grid[0][j];

        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int prev_j = 0; prev_j < n; prev_j++)
                {
                    if (dp[i - 1][prev_j] != INT_MAX)
                    {
                        int cost = dp[i - 1][prev_j] + moveCost[grid[i - 1][prev_j]][j] + grid[i][j];
                        dp[i][j] = min(dp[i][j], cost);
                    }
                }
            }
        }

        int min_cost = INT_MAX;
        for (int j = 0; j < n; j++)
            min_cost = min(min_cost, dp[m - 1][j]);

        return min_cost;
    }
};