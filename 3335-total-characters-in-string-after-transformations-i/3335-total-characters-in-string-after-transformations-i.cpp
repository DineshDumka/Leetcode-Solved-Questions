class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int MOD = 1e9 + 7;
        vector<long long> mpp(26, 0);
        for (auto ch : s) {
            mpp[ch - 'a']++;
        }
        while (t--) {
            vector<long long> mpp1(26, 0);
            for (int i = 0; i < 25; i++) {
                mpp1[i + 1] = (mpp1[i + 1] + mpp[i]) % MOD;
            }
            mpp1[0] = (mpp1[0] + mpp[25]) % MOD;
            mpp1[1] = (mpp1[1] + mpp[25]) % MOD;
            mpp = mpp1;
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            cnt = (cnt + mpp[i]) % MOD;
        }
        return cnt;
    }
};
