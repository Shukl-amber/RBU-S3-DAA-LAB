#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = -10001, max_sum = sum;
        if (nums.size() == 1)
            return nums[0];

        for (int i : nums)
        {
            if (sum < 0)
                sum = 0;
            sum += i;
            if (sum > max_sum)
                max_sum = sum;
            ;
        }
        return max_sum;
    }
};
