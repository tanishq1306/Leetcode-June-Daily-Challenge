class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int res = 1000;
        
        for (int i = 0; i < n - 2; i++) {
            int start = i + 1;
            int end = n - 1;
           
            while (start < end) {
                long long sum = nums[i] + nums[start] + nums[end];
                if (abs(target - sum) < abs(res - target)) {
                    res = sum;
                }
            
                if (sum <= target) {
                    start++;
                }
                else {
                    end--;
                }
            }
        }
        
        return res;
    }
};
