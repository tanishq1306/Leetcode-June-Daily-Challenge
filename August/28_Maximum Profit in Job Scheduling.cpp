class Solution {
public:
    static bool cmp (vector<int> a, vector<int> b) {
        return a[1] < b[1];
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> v;
        
        for (int i = 0; i < startTime.size(); i++) {
            v.push_back({startTime[i] , endTime[i] , profit[i]});
        }
        
        sort(v.begin() , v.end(), cmp);
        vector<int> dp(n);
        dp[0] = v[0][2];
        
        for (int i = 1; i < n; i++) {
            int inc = v[i][2];
            int lNConflict = -1;
            
            for (int j = i - 1; j >= 0; j--) {
                if (v[j][1] <= v[i][0]) {
                    lNConflict = j;
                    break;
                }
            }
            
            if (lNConflict != -1) {
                inc += dp[lNConflict];
            }
            
            dp[i] = max(inc, dp[i - 1]);
        }
        
        return dp[n - 1];  
    }
};
