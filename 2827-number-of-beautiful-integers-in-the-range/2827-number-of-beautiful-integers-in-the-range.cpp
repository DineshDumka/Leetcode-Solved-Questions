class Solution {
public:
    //states :  dp[level][tlo][thi][sum][even][odd][taken]
    int dp[11][2][2][21][11][11][2];
    int len;

    int rec(int level, int tlo, int thi, int sum, int even_cnt, int odd_cnt,
            int taken, const string &l, const string &r, int mod) {
        if (level == len) {
            return taken && (even_cnt == odd_cnt) && (sum % mod == 0);
        }

        if (dp[level][tlo][thi][sum][even_cnt][odd_cnt][taken] != -1)
            return dp[level][tlo][thi][sum][even_cnt][odd_cnt][taken];

        int ans = 0;
        int lo = (tlo ? l[level] - '0' : 0);
        int hi = (thi ? r[level] - '0' : 9);

        for (int i = lo; i <= hi; i++) {
            int ntlo = tlo && (i == l[level] - '0');
            int nthi = thi && (i == r[level] - '0');
            int ntaken = taken || (i != 0);

            int new_even = even_cnt, new_odd = odd_cnt, new_sum = sum;
            if (ntaken) {
                if (i % 2 == 0) new_even++;
                else new_odd++;
                new_sum = (sum * 10 + i) % mod;
            }

            ans += rec(level + 1, ntlo, nthi, new_sum, new_even, new_odd, ntaken, l, r, mod);
        }

        return dp[level][tlo][thi][sum][even_cnt][odd_cnt][taken] = ans;
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        string l = to_string(low), r = to_string(high);
        int diff = r.size() - l.size();
        l = string(diff, '0') + l;
        len = r.size();
        memset(dp, -1, sizeof(dp));
        return rec(0, 1, 1, 0, 0, 0, 0, l, r, k);
    }
};
