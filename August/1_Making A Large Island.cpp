class Solution {
public:
    int explore(vector<vector<int>> &grid, vector<vector<bool>> &vis, vector<vector<int>> &v, int i, int j, int group_number) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid.size() || vis[i][j] || grid[i][j] == 0) {
            return 0;
        }
        
        vis[i][j] = true;        
        v[i][j] = group_number;
        return (1 + explore(grid, vis, v, i - 1,  j, group_number) 
                 + explore(grid, vis, v, i + 1,  j, group_number) 
                 + explore(grid, vis, v, i,  j - 1, group_number)
                 + explore(grid, vis, v, i,  j + 1, group_number));
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> v(n, vector<int>(n, 0));
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        int group_number = 1;
        
        map<int, int> group_size;
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    group_size[group_number] = explore(grid, vis, v, i, j, group_number);
                    res = max(res, group_size[group_number]);
                    group_number++;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    set<int> vis_grp;
                    int islands = 1;
                    
                    if (i - 1 >= 0) {
                        islands += group_size[v[i-1][j]];
                        vis_grp.insert(v[i-1][j]);
                    }
                
                    if (i + 1 < n && vis_grp.find(v[i+1][j]) == vis_grp.end()) { 
                        islands += group_size[v[i+1][j]];
                        vis_grp.insert(v[i+1][j]);
                    }
                    
                    if (j - 1 >= 0 && vis_grp.find(v[i][j-1]) == vis_grp.end()) {
                        islands += group_size[v[i][j-1]];
                        vis_grp.insert(v[i][j-1]);   
                    }
                    
                    if (j + 1 < n && vis_grp.find(v[i][j+1]) == vis_grp.end()) {
                        islands += group_size[v[i][j+1]];
                        vis_grp.insert(v[i][j+1]);   
                    }
                        
                    res = max(islands, res);
                }
            }
        }
        
        return res;
    }
};
