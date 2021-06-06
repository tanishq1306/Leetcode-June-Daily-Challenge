class Solution {
public:
    /*         [x-1, y]
       [x,y-1]  [x ,y]  [x,y+1]
               [x+1, y]
    */
    int dir_x[4] = {-1, 0, 0, 1};
    int dir_y[4] = {0, -1, 1, 0};
    
    bool isValid(int x, int y, int n, int m) {
        if (x >= 0 && y >= 0 && x < n && y < m) {
            return true;
        }
        return false;
    }
    
    int bfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 1;
        vis[i][j] = true;
        
        queue<pair<int,int>> q;
        q.push({i, j});
        
        while(!q.empty()) {
            pair<int, int> qTop = q.front();
            q.pop();
            
            //see all four neighbours and push acc.
            for (int xy = 0; xy < 4; xy++) {
                int nx = qTop.first + dir_x[xy];
                int ny = qTop.second + dir_y[xy];
                    
                if (isValid(nx, ny, n, m) && grid[nx][ny] == 1 && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                    cnt++;
                } 
            }
        }
        
        return cnt;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == false) {
                    maxArea = max(bfs(grid, vis, i, j), maxArea);            
                }
            }
        }
        
        return maxArea;
    }
};
