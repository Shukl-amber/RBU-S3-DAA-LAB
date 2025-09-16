#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> arr;

void Subarray(ll ans)
{
    ll maxSum = INT_MIN;
    ll start = 0, end = 0;

    for (ll i = 0; i < arr.size(); i++)
    {
        for (ll j = i; j < arr.size(); j++)
        {
            ll currentSum = 0;
            for (ll k = i; k <= j && currentSum <= ans; k++)
                currentSum += arr[k];
            if (currentSum == ans)
            {
                start = i;
                end = j;
                goto found;
            }
        }
    }

found:
    cout << "Maximum Sum Subarray is: [ ";
    for (ll i = start; i <= end; i++)
        cout << arr[i] << " ";
    cout << "]" << endl;
}

ll DAC(ll left, ll right, ll constraint)
{
    if (left > right)
        return INT_MIN;

    if (left == right)
        if (arr[left] <= constraint)
            return arr[left];
        else
            return INT_MIN;

    ll mid = left + (right - left) / 2;

    ll leftMax = DAC(left, mid, constraint);

    ll rightMax = DAC(mid + 1, right, constraint);

    ll sum = 0, leftSum = INT_MIN, rightSum = INT_MIN;

    for (ll i = mid - 1; i >= left; i--)
    {
        sum += arr[i];
        if (sum <= constraint)
            leftSum = max(leftSum, sum);
    }

    sum = 0;

    for (ll i = mid; i <= right; i++)
    {
        sum += arr[i];

        if (sum <= constraint)
            rightSum = max(rightSum, sum);

        if (leftSum != INT_MIN && leftSum + sum <= constraint)
            rightSum = max(rightSum, leftSum + sum);
    }

    ll cross = max(leftSum, rightSum);

    return max({leftMax, rightMax, cross});
}

int main()
{
    ll size, constraint;
    cout << "Enter Size of Array: ";
    cin >> size;

    arr.resize(size);

    if (!arr.size())
    {
        cout << "ERROR: Empty Array" << endl;
        return 0;
    }

    cout << "Enter Array: ";
    for (ll i = 0; i < size; i++)
        cin >> arr[i];

    cout << "Enter Resource Constraint: ";
    cin >> constraint;

    ll ans = DAC(0, size - 1, constraint);

    if (ans == INT_MIN)
    {
        cout << "No Feasible Subarray\n";
        return 0;
    }

    Subarray(ans);

    cout << "Maximum Sum = " << ans << endl;

    return 0;
}
