class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> res;
        
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            int diff = abs(x - arr[i]);
            if (pq.size() >= k) {
                if (diff == pq.top().first && arr[i] < pq.top().second) {
                    pq.pop();
                    pq.push({diff, arr[i]});
                }
                else if (diff < pq.top().first) {
                    pq.pop();
                    pq.push({diff, arr[i]});
                }
            }
            else {
                pq.push({diff, arr[i]}); 
            }
        }
        
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};
