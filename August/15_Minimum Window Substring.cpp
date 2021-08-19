class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        string res;
        if (n < m) {
            return res;
        }
    
        map<char, int> hash_t, hash_patt;
        for (char ch: t) {
            hash_t[ch]++;
        }
        
        int l = 0;
        int match_cnt = 0;
        
        for (int r = 0; r < n; r++) {
            hash_patt[s[r]]++;
            
            if (hash_patt[s[r]] <= hash_t[s[r]]) {
                match_cnt++;
            }
            
            if (match_cnt == m) {
                while (hash_patt[s[l]] > hash_t[s[l]] || hash_t[s[l]] == 0) {
                    if (hash_patt[s[l]] > hash_t[s[l]] && hash_t[s[l]] != 0) {
                        hash_patt[s[l]]--;
                    }
                    
                    l++;
                }
                
                int len = r - l + 1;
                if (res.size() == 0 || len < res.size()) {
                    res = s.substr(l, len);
                }
            }
        }
      
        return res;
    }
};
