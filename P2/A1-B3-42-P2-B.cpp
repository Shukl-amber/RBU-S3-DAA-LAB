#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

const double unreachable = 999999.00;

double euclidean_dist(double x1, double y1, double x2, double y2);

int find(vector<int>& parent, int u) {
    if (parent[u] != u) {
        parent[u] = find(parent, parent[u]);
    }
    return parent[u];
}

void unionSets(vector<int>& parent, vector<int>& rank, int u, int v) {
    int rootU = find(parent, u);
    int rootV = find(parent, v);
    
    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

int main(void) {
    int cities;
    cout << "Enter number of cities (<= 6): ";
    cin >> cities;

    vector<string> city_names(cities);
    vector<vector<double>> geoloc(cities, vector<double>(2));
    
    for (int i = 0; i < cities; i++) {
        cout << "Enter Name Of City " << i + 1 << ": ";
        cin >> city_names[i];
        cout << "Enter Geolocation x of City " << i + 1 << ": ";
        cin >> geoloc[i][0];
        cout << "Enter Geolocation y of City " << i + 1 << ": ";
        cin >> geoloc[i][1];
    }

    vector<vector<double>> distances(cities, vector<double>(cities));
    
    for (int i = 0; i < cities; i++) {
        for (int j = 0; j < cities; j++) {
            if (i == j) {
                distances[i][j] = unreachable;
            } else {
                distances[i][j] = euclidean_dist(geoloc[i][0], geoloc[i][1], geoloc[j][0], geoloc[j][1]);
            }
        }
    }

    vector<pair<double, pair<int, int>>> sorted_routes;

    for (int i = 0; i < cities; i++) {
        for (int j = i + 1; j < cities; j++) {
            if (distances[i][j] != unreachable) {
                sorted_routes.push_back({distances[i][j], {i, j}});
            }
        }
    }

    sort(sorted_routes.begin(), sorted_routes.end());

    vector<int> parent(cities);
    vector<int> rank(cities, 0);
    for (int i = 0; i < cities; i++) {
        parent[i] = i;
    }

    double total_cost = 0.0;
    vector<pair<string, string>> mst_edges;

    for (const auto& route : sorted_routes) {
        int u = route.second.first;
        int v = route.second.second;
        double dist = route.first;

        if (find(parent, u) != find(parent, v)) {
            unionSets(parent, rank, u, v);
            total_cost += dist;
            mst_edges.push_back({city_names[u], city_names[v]});
        }
    }

    cout << "\nMST Edges:\n";
    for (const auto& edge : mst_edges) {
        cout << edge.first << " - " << edge.second << endl;
    }
    cout << "Total cost of MST: " << total_cost << endl;

    return 0;
}

double euclidean_dist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2));
}
