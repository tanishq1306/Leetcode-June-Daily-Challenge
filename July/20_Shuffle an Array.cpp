class Solution {
private:
    vector<int> org;

public:
    Solution(vector<int>& nums) {
        org = nums;    
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return org;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
		// Algorithm
		// 1 2 3 4 5 (1st iteration choose any index and swap with last index 5)
		// 1 2 5 3|4 (2nd iteration choose any index from (1-4) and swap with index 4)
		// 1 2 3|5 4 (and so on...)
		
        vector<int> shuffled = org;
        
        for (int i = shuffled.size() -  1; i >= 0; i--) {
            int random_indx = rand() % (i + 1);
            swap(shuffled[i], shuffled[random_indx]);
        }
        
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
