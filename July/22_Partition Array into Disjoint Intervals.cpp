class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxLeft(nums.begin(), nums.end());
        vector<int> minRight(nums.begin(), nums.end());
        
        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i-1], maxLeft[i]);
        }
        
        for (int i = n - 2; i >= 0; i--) {
            minRight[i] = min(minRight[i+1], minRight[i]);
        }
        
        for (int i = 0; i < n - 1; i++) {
            if (maxLeft[i] <= minRight[i+1]) {
                return i + 1;
            }
        }
        
        return -1;
    }
};
