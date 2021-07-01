class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int res = 0;
        int start = 0, end = 0;
        int windowCount = 0;
        
        while (end < nums.size()) {
            // element within the range add subarray to final result
            if (nums[end] >= left && nums[end] <= right) {
                windowCount = end - start + 1;
            }
            
            // element outside the right range 
            // reset start and reset window
            else if (nums[end] > right) {
                windowCount = 0;
                start = end + 1;
            } 
            // element less than range no chanage
            
            res += windowCount;
            end++;
        }

        return res;
    }
};
