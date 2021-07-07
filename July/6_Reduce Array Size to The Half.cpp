class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int, int> unmp;
        for (int i = 0; i < n; i++) {
            unmp[arr[i]]++;
        }
        
        vector<pair<int, int>> v;
        for (const auto &it: mp) {
            v.push_back({it.second, it.first});
        }
        
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        
        int res = 0, k = n;
        for (const auto &it: v) {
            res++;
            k -= it.first;
            
            if (k <= (n / 2)) {
                break;
            }
        }
        
        return res;
    }
};
