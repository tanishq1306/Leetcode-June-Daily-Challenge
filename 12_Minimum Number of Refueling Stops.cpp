class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pastStations;
        
        int ans = 0;
        for (int i = 0; i < (int)stations.size(); i++) {
            while (startFuel < stations[i][0]) {
                if (pastStations.empty()) {
                    return -1;
                }
                
                startFuel += pastStations.top();
                pastStations.pop();
                ans++;
            }
            
            pastStations.push(stations[i][1]);
        }
        
        while (!pastStations.empty() && startFuel < target) {
            startFuel += pastStations.top();
            pastStations.pop();
            ans++;
        }
    
        if (startFuel < target)
            ans = -1;
        
        return ans;
    }
};
