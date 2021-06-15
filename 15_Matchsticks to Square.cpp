class Solution {
public:
    bool solve(vector<int>& matchsticks, int i, vector<int> sides) {
        if(i == matchsticks.size()) {
            if(sides[0] == 0 && sides[1] == 0 && sides[2] == 0 && sides[3] == 0) {
                return true;
            } 
            else {
                return false;
            }
        }


        for (int j = 0; j < 4; j++) {
            if (matchsticks[i] > sides[j]) 
                continue;
            
            sides[j] -= matchsticks[i];
            if (solve(matchsticks, i + 1, sides)) 
                return true;
            
            sides[j] += matchsticks[i];
        }

        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4) 
            return false;

        int perimeter = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (perimeter % 4 != 0) 
            return false;
        
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        
        int side = perimeter / 4;
        vector<int> sides(4, side);

        return solve(matchsticks, 0, sides);
    }
};
