#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> resultTemp;
vector<ll> resultPressure;

clock_t start_time, end_time;

ll times = 10000;
int minTemp = INT_MAX, maxPressure = -1;

void generateTemp(ll times)
{
    for (ll i = 0; i < times; i++)
        resultTemp.push_back((rand() % (71)) - 20);
}

void generatePressure(ll times)
{
    for (ll i = 0; i < times; i++)
        resultPressure.push_back((rand() % (101)) + 950);
}

void linearSearch()
{
    for (auto i : resultTemp)
        if (i < minTemp)
            minTemp = i;

    for (auto i : resultPressure)
        if (i > maxPressure)
            maxPressure = i;

    cout << "Minimum Temperature: " << minTemp << endl;
    cout << "Maximum Pressure: " << maxPressure << endl;
}

void quadraticSearch()
{
    for (auto i : resultTemp)
    {
        auto test = i;
        bool found = true;

        for (auto j : resultTemp)
        {
            if (j < i)
            {
                found = false;
            }
        }

        if (found)
        {
            minTemp = i;
            cout << "Minimum Temperature: " << minTemp << endl;
            break;
        }
    }

    for (auto i : resultPressure)
    {
        auto test = i;
        bool found = true;

        for (auto j : resultPressure)
        {
            if (j > i)
            {
                found = false;
            }
        }

        if (found)
        {
            maxPressure = i;
            cout << "Maximum Pressure: " << maxPressure << endl;
            break;
        }
    }
}

int main()
{

    srand(time(0));

    start_time = clock();
    generateTemp(times);
    generatePressure(times);
    end_time = clock();
    cout << "Time Taken By Generation: " << ((double)(end_time - start_time)) / CLOCKS_PER_SEC << endl;

    // Linear Method
    start_time = clock();
    linearSearch();
    end_time = clock();
    cout << "Time Taken By Linear Method: " << ((double)(end_time - start_time)) / CLOCKS_PER_SEC << endl;

    // Quadratic Method
    start_time = clock();
    quadraticSearch();
    end_time = clock();
    cout << "Time Taken By Quadratic Method: " << ((double)(end_time - start_time)) / CLOCKS_PER_SEC << endl;
}