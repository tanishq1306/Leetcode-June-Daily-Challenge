class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        map<char, char> mp;
        
        for (int i = 0; i < n; i++) {
            if (mp.find(s[i]) != mp.end() && (mp[s[i]] != t[i])) {
                return false;
            }   
            else {
                mp[s[i]] = t[i];
            }
        }
        
        mp.clear();
        
        for (int i = 0; i < n; i++) {
            if (mp.find(t[i]) != mp.end() && (mp[t[i]] != s[i])) {
                return false;
            }   
            else {
                mp[t[i]] = s[i];
            }
        }
        
        return true;
    }
};
