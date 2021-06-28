class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for (char ch: s) {
            if (stk.empty()) {
                stk.push(ch);
            }
            else {
                if (stk.top() == ch) {
                    stk.pop();
                }
                else {
                    stk.push(ch);
                }
            }
        }
        
        string res;
        while(!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
