#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> resultTemp;

clock_t start_time, end_time;

ll times = 1000000;

void generateTemp(ll times)
{
    for (ll i = 0; i < times; i++)
        resultTemp.push_back(rand() % (50 - 20 + 1) + 20);
}

void linearSearch()
{
    for (ll i = 0; i < resultTemp.size(); i++)
        if (resultTemp[i] >= 30)
        {
            cout << "\n\nFirst Occourence: " << resultTemp[i] << " At Index: " << i << endl;
            break;
        }
}

void binarySearch()
{
    ll start = 0, end = resultTemp.size() - 1, mid;
    bool found = false;

    while (start <= end && !found)
    {

        mid = (end + start) / 2;

        if (resultTemp[mid] >= 30)
        {
            cout << "\nFound Occourence: " << resultTemp[mid] << " At Index: " << mid << endl;
            found = true;
        }
        else if (resultTemp[mid] < 30)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
}

int main()
{

    srand(time(0));

    generateTemp(times);

    // Sorting
    start_time = clock();
    sort(resultTemp.begin(), resultTemp.end());
    end_time = clock();
    cout << "\nTime Taken By Sorting: " << ((double)(end_time - start_time)) / CLOCKS_PER_SEC << " Seconds" << endl;

    // Linear Method
    start_time = clock();
    linearSearch();
    end_time = clock();
    cout << "Time Taken By Linear Method: " << ((double)(end_time - start_time)) / CLOCKS_PER_SEC << " Seconds" << endl;

    // Binary Method
    start_time = clock();
    binarySearch();
    end_time = clock();
    cout << "Time Taken By Binary Method: " << ((double)(end_time - start_time)) / CLOCKS_PER_SEC << " Seconds\n\n"
         << endl;
}