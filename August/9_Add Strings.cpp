class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        string res;
        int n = num1.size();
        int m = num2.size();
        int sum = 0, carry = 0, l = 0, r = 0;
        
        while (l < n && r < m) {
            sum = (num1[l] - '0') + (num2[r] - '0') + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            res += to_string(sum);
            l++;
            r++;
        }
        
        while (l < n) {
            sum = (num1[l] - '0') + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            res += to_string(sum);
            l++;
        }
        
        while (r < m) {
            sum = (num2[r] - '0') + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            res += to_string(sum);
            r++;
        }
        
        if (carry > 0) {
            res += to_string(carry);
        } 
        
        reverse(res.begin(), res.end());
        return res;
    }
};
