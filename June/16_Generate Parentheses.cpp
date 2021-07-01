class Solution {
public:
    bool check(string &seq) {
        int cnt = 0;
        for (int i = 0; i < (int)seq.size(); i++) {
            if (seq[i] == '0')
                cnt--;
            else 
                cnt++;
            
            if (cnt < 0)
                return false;
        }
        
        return (cnt == 0);
    }
    
    string generateParanthesisStr(string &seq) {
        for (int i = 0; i < (int)seq.size(); i++)
            if (seq[i] == '1')
                seq[i] = '(';
            else 
                seq[i] = ')';
        
        return seq;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        n = 2 * n;
        for (int i = 0; i < (1 << n); i++) {
            string str(n, '0');
            int cnt0 = 0, cnt1 = 0;
            
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    str[j] = '1';
                    cnt1++;
                }        
                else {
                    cnt0++;
                }
            }
            
            if ((cnt1 == cnt0) && check(str)) {
                ans.push_back(generateParanthesisStr(str));
            }
        }
        
        return ans;
    }
};
