class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> x, y;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    x.insert(i);
                    y.insert(j);
                }  
            }
        }
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (x.find(i) != x.end() || y.find(j) != y.end()) {
                    matrix[i][j] = 0;
                }    
            }
        }
    }
};
