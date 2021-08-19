/*
    Idea

    We greedily process elements starting from the smallest value, WHY smallest value but not an arbitrary value?
    Because since it's the smallest values, let say x, there is only one choice to pair with x:
    If x is a positive number, then it pairs with y = x*2, for example: x = 4 pair with y = 8.
    If x is a non-positive number, then it pairs with y = x/2, for example: x = -8 pair with y = -4.
    If there is no corresponding y then it's IMPOSSIBLE, return FALSE.
    If it's an arbitrary value, let say x, there are two choices, either x/2 or x*2 is also a good pairing with x     (no matter if x is a possible or negative number), if we choose x/2 or x*2 to pair with x, it maybe WRONG,       because some other elements may need it to make pair.
    
    // ***** IMP ***** //
    For example: arr = [2, 4, 1, 8]
    If we process x = 2 first, then there are 2 choices, either 4 or 1 can be paired with 2, if we choose 4 -> we     got WRONG ANSWER.
    Because 8 needs 4, so 2 should be paired with 1.
    So we need to sort our arr array first.
    When a pair of (x and y) match, we need to decrease their count. So we need to use a HashTable data structure     to count the frequency of elements in the arr array.
*/
    
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> track;
        int n = arr.size();
        int c = 0;
        
        sort(arr.begin(),arr.end(),[](int a, int b){return abs(a) < abs(b);});
        
        for(int i = 0; i < arr.size(); i++) {
            track[arr[i]]++;
        }
        
        for(int i = 0; i < arr.size(); i++) {       
            if (track[arr[i]] == 0)  
                continue;
            
            if(arr[i] == 0 && track[arr[i]] >= 2)
                c++, track[arr[i]] -= 2;
            
            if (arr[i] != 0 && track[arr[i] * 2] > 0) 
                c++, track[arr[i] * 2]--, track[arr[i]]--;
        }
        
        return c == n / 2;
    }
};
