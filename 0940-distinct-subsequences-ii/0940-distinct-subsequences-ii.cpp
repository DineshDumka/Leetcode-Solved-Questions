class Solution {
public:
    int distinctSubseqII(string s) {
        int mod = 1e9 + 7;
        int n = s.size();
        vector<int> dp(n + 1); 
        vector<int> last(26, -1); 

        dp[0] = 1; 

        for (int i = 1; i <= n; ++i) {
            dp[i] = (2LL * dp[i - 1]) % mod;
            int ch = s[i - 1] - 'a';

            if (last[ch] != -1) {
                dp[i] = (dp[i] - dp[last[ch] - 1] + mod) % mod;
            }

            last[ch] = i;
        }

        return (dp[n] - 1 + mod) % mod; 
    }
};
