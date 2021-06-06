class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        // empty sequence
        if ((int)a.size() == 0) 
            return 0;
        
        set<int> s(a.begin(), a.end());
        vector<int> nums(s.begin(), s.end());
        
        int ans = 0, cnt = 1;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                cnt++;
            }
            else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        
        ans = max(ans, cnt);
        return ans;
    }
};
