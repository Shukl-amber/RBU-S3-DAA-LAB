#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1]; 
        });
        
        int totalUnits = 0;
        int boxesUsed = 0;
        
        for (auto& box : boxTypes) {
            int availableBoxes = box[0];   
            int unitsPerBox = box[1];      
            
            int boxesToTake = min(availableBoxes, truckSize - boxesUsed);
            
            totalUnits += boxesToTake * unitsPerBox;
            boxesUsed += boxesToTake;
            
            if (boxesUsed == truckSize) {
                break;
            }
        }
        
        return totalUnits;
    }
};

