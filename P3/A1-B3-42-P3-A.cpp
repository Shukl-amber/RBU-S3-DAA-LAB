#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
#define pb push_back
#define pop pop_back

double trucksize = 850, n = 50;

// In Vector Box Dimention 1 is Weight || Dimention 2,0 is Profit || Dimention 2,1 is Profit/Weight

double max_profit(vector<vector<double>> box)
{
    double profit = 0, current_weight = 0;

    sort(box.begin(), box.end(), [](const vector<double> &a, const vector<double> &b)
         { return a[1] > b[1]; });

    int i = 0;

    while (current_weight < trucksize && i < n)
    {
        if (current_weight + box[i][0] >= trucksize)
        {
            double remaining_space = trucksize - current_weight;
            if (box[i][0] > 0)
            { // Avoid division by zero
                profit += (box[i][1] * (remaining_space / box[i][0]));
            }
            current_weight = trucksize;
            break;
        }

        current_weight += box[i][0];
        profit += box[i][1];
        i++;
    }

    return profit;
}

double min_weight(vector<vector<double>> box)
{
    double profit = 0, current_weight = 0;

    sort(box.begin(), box.end(), [](const vector<double> &a, const vector<double> &b)
         { return a[0] < b[0]; });

    int i = 0;

    while (current_weight < trucksize && i < n)
    {
        if (current_weight + box[i][0] >= trucksize)
        {
            double remaining_space = trucksize - current_weight;
            if (box[i][0] > 0)
            { // Avoid division by zero
                profit += (box[i][1] * (remaining_space / box[i][0]));
            }
            current_weight = trucksize;
            break;
        }

        current_weight += box[i][0];
        profit += box[i][1];
        i++;
    }

    return profit;
}

double pw_ratio(vector<vector<double>> box)
{
    double profit = 0, current_weight = 0;

    sort(box.begin(), box.end(), [](const vector<double> &a, const vector<double> &b)
         { return a[2] > b[2]; });

    int i = 0;

    while (current_weight < trucksize && i < n)
    {
        if (current_weight + box[i][0] >= trucksize)
        {
            double remaining_space = trucksize - current_weight;
            if (box[i][0] > 0)
            { // Avoid division by zero
                profit += (box[i][1] * (remaining_space / box[i][0]));
            }
            current_weight = trucksize;
            break;
        }

        current_weight += box[i][0];
        profit += box[i][1];
        i++;
    }

    return profit;
}

int main()
{

    vector<vector<double>> box(n, vector<double>(3, 0));

    cout << "Enter Weight of all Boxes" << endl;

    for (int i = 0; i < n; i++)
        cin >> box[i][0];

    cout << "Enter Profit Values of all Boxes" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> box[i][1];
        (box[i][0] != 0) ? (box[i][2] = (box[i][1] / box[i][0])) : (box[i][2] = 9999); // Profit/Weight Calculation
    }

    auto start_time = high_resolution_clock::now();
    cout << "\n\nProfit By Maximum Profit Method: " << max_profit(box) << endl;
    auto end_time = high_resolution_clock::now();
    auto time_taken = duration_cast<microseconds>(end_time - start_time);
    cout << "Time taken: " << time_taken.count() << " microseconds" << endl;

    start_time = high_resolution_clock::now();
    cout << "\nProfit By Minimum Weight Method: " << min_weight(box) << endl;
    end_time = high_resolution_clock::now();
    time_taken = duration_cast<microseconds>(end_time - start_time);
    cout << "Time taken: " << time_taken.count() << " microseconds" << endl;

    start_time = high_resolution_clock::now();
    cout << "\nProfit By Profit/Weight Ratio Method: " << pw_ratio(box) << endl;
    end_time = high_resolution_clock::now();
    time_taken = duration_cast<microseconds>(end_time - start_time);
    cout << "Time taken: " << time_taken.count() << " microseconds" << endl;

    return 0;
}