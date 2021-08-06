class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int n = nums.size();
        map<int, int> mp;
        
        for (int i = 0; i < n; i++) {
            int req = target - nums[i];
            if (mp.find(req) != mp.end()) {
                res.push_back(mp[req]);
                res.push_back(i);
                break;
            }
                
            mp[nums[i]] = i;
        }
        
        return res;
    }
};
