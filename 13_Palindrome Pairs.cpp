class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;
        int n = words.size();
        vector<vector<int>> ans;
        
        if(n < 2)
            return ans;
        
        for(int i = 0; i < words.size(); i++) {
            string temp = words[i];
            reverse(temp.begin(), temp.end());
            mp[temp] = i;
        }
        
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j <= words[i].size(); j++) {
                string prefix = words[i].substr(0,j);
                string suffix = words[i].substr(j);
                
                if(mp.count(prefix) && isPalindrome(suffix) && mp[prefix]!=i)
                    ans.push_back({i,mp[prefix]});
                
                if(!prefix.empty() && mp.count(suffix) && isPalindrome(prefix) && mp[suffix]!=i)
                    ans.push_back({mp[suffix],i});
            }
        }
        return ans;
    }
    
    bool isPalindrome(string s) {
        string temp = s;
        reverse(temp.begin(), temp.end());
        return temp == s;
    }
};
