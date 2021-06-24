class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size(), res = 0;
        unordered_map<string, int> unmp;
        
        for (auto &it: words)
            unmp[it]++;
        
        for (auto &it: unmp) {
            string word = it.first;
            int i = 0, j = 0, m = word.size();
            
            while (i < n && j < m) {
                if (s[i] == word[j])
                    i++,j++;
                else
                    i++;
            }
            
            if (j == m)
                res += it.second;
        }
        
        return res;
    }
};
