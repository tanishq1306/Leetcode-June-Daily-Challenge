class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (r * c != mat.size() * mat[0].size()) {
            return mat;
        }
        
        vector<vector<int>> ans(r, vector<int>(c));
        int row = 0, col = 0;
        for (int i = 0; i < (int)mat.size(); i++) {
            for (int j = 0; j < (int)mat[0].size(); j++) {
                ans[row][col] = mat[i][j];
                col = (col + 1) % c;
                if (col == 0) {
                    row++;
                }
            }
        }
        
        return ans;
    }
};
