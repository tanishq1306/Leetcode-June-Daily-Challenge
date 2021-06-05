class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        const int mod = 1e9 + 7;
        
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i].first = efficiency[i];
            v[i].second = speed[i];
        }
        
        // Keep track of the engineers by their efficiency in decreasing order.
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        
        long long res = 0, sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int i = 0; i < n; i++) {
            int eff = v[i].first;
            
            if (pq.size() < k) {
                pq.push(v[i].second);
                sum = sum + v[i].second;
            }
            else {
				// remove the smallest speed value among (k - 1) engineers
                sum = sum - pq.top() + v[i].second; 
                pq.pop();
                pq.push(v[i].second);
            }
            
            res = max(res, eff * sum);
        }
        
        return (res % mod);
    }
};
