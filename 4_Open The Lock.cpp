class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> dead;
        for (const auto &it: deadends) {
            dead.insert(it);
		}
        
        int level = 0;
        queue<string> q;
        if (dead.find("0000") == dead.end()) {
            q.push("0000");
            dead.insert("0000");
        }
        
        while (!q.empty()) {
            int level_size = q.size();
            while (level_size--) {
                string top = q.front();
                q.pop();
                
                if (top == target) {
                    return level;
                }
                
                for (int i = 0; i < 4; i++) {
                    // clockwise
                    string nxt = top;
                    nxt[i] = (nxt[i] == '9'? '0': (char)(nxt[i] + 1));
                    if (dead.find(nxt) == dead.end()) {
                        q.push(nxt);
                        dead.insert(nxt);
                    }
                    
                    // anti-clockwise
                    nxt = top;
                    nxt[i] = (nxt[i] == '0'? '9': (char)(nxt[i] - 1));
                    if (dead.find(nxt) == dead.end()) {
                        q.push(nxt);
                        dead.insert(nxt);
                    }
                }
            }
            level++;
        }
        
        return -1;
    }   
};
