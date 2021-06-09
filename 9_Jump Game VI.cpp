class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> dp(n, INT_MIN);
        priority_queue<pair<int, int>> pq;
        
        pq.push({nums[0], 0});
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
	    // remove elements with indx less than (i - k)
            while (pq.top().second < (i - k)) {
                pq.pop();
            }
            
            dp[i] = max(dp[i], nums[i] + pq.top().first);
            pq.push({dp[i], i}); 
        }
        
        return dp[n-1];
    }
};
