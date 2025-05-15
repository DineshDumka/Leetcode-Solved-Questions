class Solution {
public:
    int rec(int i, vector<int>& arr, vector<int>& dp) {
        if (dp[i] != -1) return dp[i];

        int ans = 1;

        for (int prev = 0; prev < i; ++prev) {
            if (arr[i] > arr[prev]) {
                ans = max(ans, rec(prev, arr, dp) + 1);
            }
        }
        return dp[i] = ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int res = 0;

        for (int i = 0; i < n; ++i) {
            res = max(res, rec(i, nums, dp));
        }
        return res;
    }
};
