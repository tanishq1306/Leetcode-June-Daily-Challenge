class Solution {
public:
    int dp[51][51][51];
    const int mod = 1e9 + 7;
    
    int solve(int m, int n, int maxMove, int i, int j) {
        if (maxMove < 0) {
            return 0;
        }
        
        // exceeded boundary conditions
        if (i < 0 || j < 0 || i == m || j == n) {
            return 1;
        }
        
        if (dp[i][j][maxMove] != -1) {
            return dp[i][j][maxMove];
        }
        
        long long left = solve(m, n, maxMove - 1, i, j - 1) % mod;
        long long right = solve(m, n, maxMove - 1, i, j + 1) % mod;
        long long up = solve(m, n, maxMove - 1, i - 1, j) % mod;
        long long down = solve(m, n, maxMove - 1, i + 1, j) % mod;
        
        dp[i][j][maxMove] = (left + right + up + down) % mod;
        return dp[i][j][maxMove];
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return solve(m, n, maxMove, startRow, startColumn);
    }
};
