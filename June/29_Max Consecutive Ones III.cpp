class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0, l = 0, r = 0;
        int temp_ones = 0;
        int n = nums.size();
        
        while(r < nums.size()) {
            // increase the window size
            if (nums[r] == 1) {
                r++;
            }    
            // 0 replaced with 1
            else if (temp_ones < k) {
                r++;
                temp_ones++;
            }
            // calculate window size and reduce window
            else {
                res = max(res, r - l);
                if (nums[l] == 0) {
                    temp_ones--;
                    
                }
                l++;
            }
        }
        
        res = max(res, r - l);
        return res;
    }
};
