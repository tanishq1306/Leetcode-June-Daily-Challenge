class Solution {
public:
    map<char, string> mp;
    map<pair<char,int>,int> dp;
	const int mod = 1e9 + 7;
    
	int solve(char ch, int curr_level, int nth_level) {
		if (curr_level == nth_level) {
			return dp[{ch, curr_level}] = mp[ch].size();
		}

		if (dp.find({ch, curr_level}) != dp.end()) {
			return dp[{ch, curr_level}];
		}

		int sum = 0;
		for (char c: mp[ch]) 
			sum = (sum + solve(c, curr_level + 1, nth_level)) % mod;	

		return dp[{ch, curr_level}] = sum;
	}

    int countVowelPermutation(int n) {
        mp.clear();
        dp.clear();
        
        if (n == 1) {
           return 5;
        }

        mp['a'] = "e";
        mp['e'] = "ai";
        mp['i'] = "aeou";
        mp['o'] = "iu";
        mp['u'] = "a";

        string vowel = "aeiou";
        int res = 0;
        for (char ch: vowel)
            res = (res + solve(ch, 1, n - 1)) % mod;

        return res;
    }
};

