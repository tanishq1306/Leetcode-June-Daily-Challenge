// Greedy
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) { 
        sort(boxTypes.begin(), boxTypes.end(), [&](vector<int> &a, vector<int> &b) {
            return a[1] > b[1];
            return a[0] > b[0];
        });
        
        int res = 0;
        for (int i = 0; i < (int)boxTypes.size(); i++) {
            if (boxTypes[i][0] <= truckSize) {
                res += (boxTypes[i][0] * boxTypes[i][1]);    
                truckSize -= boxTypes[i][0];
            }
            else {
                res += min(truckSize, boxTypes[i][0]) * boxTypes[i][1];
                break;
            }
        }
        
        return res;
    }
};
