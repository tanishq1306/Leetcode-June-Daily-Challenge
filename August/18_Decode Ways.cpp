class Solution {
public:
    int dp[1000];
    bool isValid(char a) {
        int val = a - '0';
        if (val >= 1 && val <= 26) {
            return true;
        }
        return false;
    }
    
    bool isValid(char a, char b) {
        if (a == '0') {
            return false;
        }
        
        int val = a - '0';
        val = (10 * val) + (b - '0'); 
        if (val >= 1 && val <= 26) {
            return true;
        }
        return false;
    }
    
    int solve(string &s, int i, int n) {
        if (i == n) {
            return 1;
        }
        
        if (dp[i] != -1) {
            return dp[i];
        }
        
        int ans = 0;
        if (isValid(s[i])) {
            ans += solve(s, i + 1, n);
        }
        
        if (i + 1 < n && isValid(s[i], s[i + 1])) {
            ans += solve(s, i + 2, n);
        }
        
        return dp[i] = ans;
    }
    
    int numDecodings(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, n);
    }
};
