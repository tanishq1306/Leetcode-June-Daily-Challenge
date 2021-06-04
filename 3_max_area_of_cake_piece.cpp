class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        
        int mod = 1e9 + 7;
        int h_max = hc[0];
        int w_max = vc[0];
        int n = hc.size();
        int m = vc.size();
        
        for (int i = 1; i < n; i++) {
            h_max = max(h_max, hc[i] - hc[i - 1]);       
        }
     
        for (int i = 1; i < m; i++) {
            w_max = max(w_max, vc[i] - vc[i - 1]);
		}
        
        h_max = max(h_max, h - hc[n - 1]);
        w_max = max(w_max, w - vc[m - 1]);
        
        return ((1LL * (h_max % mod) * (w_max % mod)) % mod);
    }
};
