class Solution {
public:
    vector<int> adj[1005];
    vector<bool> vis;
    
    bool detectCycle(int u, int parent) {
        vis[u] = true;
        for (const auto &v: adj[u]) {
            if (!vis[v]) {
                if (detectCycle(v, u)) {
                    return true;
                }
            }
            else if (v != parent) {
                return true;
            }
        }
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        vector<int> res;
        for (const auto &it: edges) {
            int a = it[0];
            int b = it[1];
            
            // add [a, b] -> edge to the graph
            adj[a].push_back(b);
            adj[b].push_back(a);
            
            vis.clear();
            vis.resize(n + 1, false);
            if (detectCycle(a, 0)) {
                res.push_back(a);
                res.push_back(b);
                break;
            }    
        }
        
        return res;
    }
};
