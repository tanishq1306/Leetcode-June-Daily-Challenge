class Solution {
public:
    int dp[1005][1005];
    
    int solve(vector<int>& stones, int i, int j, int sum) {
        if (i == j) {
            return 0;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int res = (sum - stones[i]) - solve(stones, i + 1, j, sum - stones[i]);
        res = max(res, (sum - stones[j]) - solve(stones, i, j - 1, sum - stones[j]));
        
        // cout << "[" << i << ", " << j << "] = " << res << "\n";
        return dp[i][j] = res;
    }
    
    int stoneGameVII(vector<int>& stones) {
        memset(dp, -1, sizeof(dp));
        
        int sum = accumulate(stones.begin(), stones.end(), 0);
        return solve(stones, 0, stones.size() - 1, sum);
    }
};
