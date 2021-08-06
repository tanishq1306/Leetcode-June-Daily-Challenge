class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> allSubsets;
        
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++) {
            vector<int> subset;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    subset.push_back(nums[j]);
                }        
            }
            
            allSubsets.insert(subset);
        }
        
        vector<vector<int>> vAllSubsets(allSubsets.begin(), allSubsets.end());
        return vAllSubsets;
    }
};
