class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            mp[str].push_back(strs[i]);
        }
        
        vector<vector<string>> res(mp.size());
        int i = 0;
        for (auto &it: mp) {
            for (auto &str: it.second) {
                res[i].push_back(str);
            }
            i++;
        }
        
        return res;
    }
};
