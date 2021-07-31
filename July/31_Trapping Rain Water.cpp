class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) 
            return 0;
        
        vector<int> nearestGreatestRight(n,0), nearestGreatestLeft(n,0);
        
        nearestGreatestLeft[0] = height[0];
        for (int i = 1; i < n; i++) {
            nearestGreatestLeft[i] = max(height[i], nearestGreatestLeft[i - 1]);
        }
        
        nearestGreatestRight[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            nearestGreatestRight[i] = max(height[i], nearestGreatestRight[i + 1]);
        }
        
        int trappedWater = 0;
        for (int i = 1; i < n - 1; i++) {
            trappedWater += min(nearestGreatestRight[i], nearestGreatestLeft[i]) - height[i];
        }
        
        return trappedWater;
    }
};
