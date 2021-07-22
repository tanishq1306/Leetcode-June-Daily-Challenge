class Solution {
public:
    string pushDominoes(string& s) {
        int n = s.size();
        // Case 1: L...L
        // Case 2: R...R
        // Case 3: L...R
        // Case 4: R...L
        
        for (int i = 0; i < n; i++) {
            if (s[i] != '.') {
                int j = i + 1;
                for (; j < n; j++) {
                    if (s[j] != '.')
                        break;
                }
                
                if (j < n && s[i] == s[j]) {
                    while (i <= j) {
                        s[i++] = s[j];
                    }
                }
                else if (j < n && s[i] == 'R' && s[j] == 'L') {
                    int l = i + 1, r = j - 1;
                    while (l < r) {
                        s[l++] = 'R';
                        s[r--] = 'L';
                    }
                }
                
                i = j - 1;
            }
        }
        
        // Extra iteration of cases 
        // Case 5: ....L
        // Case 6: R....
        
        int indx = 0;
        while (indx < n && s[indx] == '.') {
            indx++;
        }
        
        if (indx < n && s[indx] == 'L') {
            while (indx >= 0) {
                s[indx--] = 'L';
            }    
        }
        
        indx = n - 1;
        while (indx >= 0 && s[indx] == '.') {
            indx--;
        }
        
        if (indx >=0 && s[indx] == 'R') {
            while (indx < n) {
                s[indx++] = 'R';
            }    
        }
        
        return s;
    }
};
