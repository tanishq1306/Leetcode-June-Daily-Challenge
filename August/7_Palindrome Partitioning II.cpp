class Solution {
public:
    
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        for (int gap = 0; gap < n; gap++) {
            for (int i = 0, j = gap; j < n; i++, j++) {
                if (gap == 0) {
                    dp[i][j] = true;
                }
                else if (gap == 1) {
                    dp[i][j] = (s[i] == s[j]);
                }
                else {
                    if (s[i] == s[j] && dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                    }
                    else {
                        dp[i][j] = false;
                    }
                }
            }    
        }
        
        vector<int> t(n);
        t[0] = 0;
        
        for (int i = 1; i < n; i++) {
            if (dp[0][i]) {
                t[i] = 0;
            }
            else {
                int minimumCuts = 1e5;
                for (int j = i; j >= 1; j--) {
                    if(dp[j][i]) {
                        minimumCuts = min(minimumCuts, t[j - 1]);    
                    }
                }

                t[i] = minimumCuts + 1;
            }
        }
        
        return t[n - 1];
    }
};

//class Solution {
//public:
    //bool isPalindrome(string &s, int i, int j) {
        //while (i < j) {
            //if (s[i++] != s[j--]) {
                //return false;
            //}
        //}
        
        //return true;
    //}
    
    //int minCutPalindrome(string &s, vector<vector<int>>& dp, int i, int j) {
        //if (i >= j || isPalindrome(s, i, j)) {
            //return 0;
        //}
        
        //if (dp[i][j] != -1) {
            //return dp[i][j];    
        //}
        
        //int res = 1e5;
        //for (int k = i; k < j; k++) {
            //int left = ((dp[i][k] != -1)? dp[i][k]: minCutPalindrome(s, dp, i, k));
            //int right = ((dp[k+1][j] != -1)? dp[k+1][j]: minCutPalindrome(s, dp, k+1, j));
            
            //res = min(res, 1 + left + right);
        //}
        
        //return dp[i][j] = res;
    //}
    
    //int minCut(string s) {
        //vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        //return minCutPalindrome(s, dp, 0, s.size() - 1);
    //}
//};
