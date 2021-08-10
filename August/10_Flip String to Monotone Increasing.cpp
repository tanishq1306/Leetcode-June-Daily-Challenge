class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> zeros(n, 0), ones(n, 0);
        
        zeros[0] = (s[0] == '0');
        ones[0] = (s[0] == '1');
        
        for (int i = 1; i < n; i++) {
            zeros[i] = (s[i] == '0') + zeros[i - 1];
            ones[i] = (s[i] == '1') + ones[i - 1];
        }
    
        int res = 1e6;
        for (int cnt = 0; cnt < n; cnt++) {
            int req_zeros = cnt;
            int req_ones = n - cnt;
            
            int have_zeros = (cnt - 1 >= 0? zeros[cnt - 1]: 0);
            int have_ones = ones[n - 1] - (cnt - 1 >= 0? ones[cnt - 1]: 0);
            
            res = min(res, (req_zeros - have_zeros) + (req_ones - have_ones));
        }
        
        res = min(res, zeros[n - 1]);
        res = min(res, ones[n - 1]);
        return res;
    }
};
