class Solution {
public:
    int dp[1005][1005];
    bool solve(string s1, int i, string s2, int j, int k, string s3) {
        if (i == s1.size() && j == s2.size() && k == s3.size()) {
            return dp[i][j] = 1;
        }
        
        if(dp[i][j] != -1) {
            return (dp[i][j] == 1? true: false);
        }
        
        bool ans = false;
        if (i < s1.size() && s1[i] == s3[k]) {
            ans = solve(s1, i + 1, s2, j, k + 1, s3);
        }
        if (j < s2.size() && s2[j] == s3[k]) {
            ans = ans | solve(s1, i, s2, j + 1, k + 1, s3);
        }
        
        return dp[i][j] = (ans == true? 1: 0);
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof(dp));
        
        string res = "";
        return solve(s1, 0, s2, 0, 0, s3);
    }
};
