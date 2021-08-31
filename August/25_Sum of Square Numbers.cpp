class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long i = 0; i * i <= c; i++) {
            long long j = c - (i * i);
            if (j < 0) {
                break;
            }
            
            long long sq = sqrt(j);
            if (j == 1LL * sq * sq) {
                return true;
            }
        }
        
        return false;
    }
};
