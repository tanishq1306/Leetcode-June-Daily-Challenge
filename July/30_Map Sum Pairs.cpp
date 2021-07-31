class MapSum {
private: 
    map<string, int> mp;
    
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mp[key] = val;
    }
    
    int sum(string prefix) {
        int total = 0;
        
        for (const auto &it: mp) {
            int i = 0;
            
            while (i < prefix.size() && it.first[i] == prefix[i]) {
                i++;
            }
            
            if (i == prefix.size()) {
                total += it.second;
            }
        }
        
        return total;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
