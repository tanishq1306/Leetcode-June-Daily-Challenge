class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
            
        int start = 0, end = nums.size() - 1;
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if (mid > 0 && mid < nums.size() - 1) {
                if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                    return mid;
                else if(nums[mid] < nums[mid+1])
                    start = mid + 1;
                else if(nums[mid] < nums[mid-1])
                    end = mid - 1;
            }
            if (mid == 0) {
                if (nums[mid] > nums[mid + 1])
                    return mid;
                    
                start = mid + 1;
            }
            if (mid == nums.size() - 1) {
                if (nums[mid] > nums[mid - 1])
                    return mid;
                    
                end = mid - 1;
            }
        }
        
        return -1;
    }
};
