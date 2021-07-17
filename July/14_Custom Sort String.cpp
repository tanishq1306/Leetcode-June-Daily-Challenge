class Solution {
public:
    string customSortString(string order, string str) { 
        map<char, int> mp1, mp2;
        
        string s = "";
        for(int i = 0; i < str.size(); i++)
            mp1[str[i]]++;
        
        for(int i = 0; i < order.size(); i++) {
            mp2[order[i]] = 1;
            // string(num of occ, char)
            s += string(mp1[order[i]], order[i]);   
        }
        
        for(int i = 0; i < str.size(); i++) {
            if (mp2.find(str[i]) != mp2.end())
                continue;
            else
                s += str[i];
        }
        
        return s;
    }
};
