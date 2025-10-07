#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + freq[i];

        for (int i = 0; i < n; i++)
            dp[i][i] = freq[i];

        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i + len - 1 < n; i++)
            {
                int j = i + len - 1;
                int totalFreq = prefix[j + 1] - prefix[i];
                int best = INT_MAX;

                for (int r = i; r <= j; r++)
                {
                    int leftCost = dp[i][r - 1];
                    int rightCost = dp[r + 1][j];
                    best = min(best, leftCost + rightCost + totalFreq);
                }

                dp[i][j] = best;
            }
        }

        return dp[0][n - 1];
    }
};
