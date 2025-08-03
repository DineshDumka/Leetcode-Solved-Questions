class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        // Create a map of position to amount
        map<int, int> mp;
        for (auto& f : fruits) {
            mp[f[0]] = f[1];
        }

        // Build prefix sums for positions in a compressed vector
        vector<int> pos;
        for (auto& f : fruits) pos.push_back(f[0]);

        int n = pos.size();
        vector<int> preSum(n + 1, 0);
        for (int i = 0; i < n; ++i)
            preSum[i + 1] = preSum[i] + mp[pos[i]];

        int ans = 0;

        // Walk k steps left then right
        for (int x = 0; x <= k; ++x) {
            int left = startPos - x;
            int rem = k - 2 * x;
            if (rem < 0) continue;
            int right = startPos + rem;

            int l = lower_bound(pos.begin(), pos.end(), left) - pos.begin();
            int r = upper_bound(pos.begin(), pos.end(), right) - pos.begin();
            ans = max(ans, preSum[r] - preSum[l]);
        }

        // Walk k steps right then left
        for (int x = 0; x <= k; ++x) {
            int right = startPos + x;
            int rem = k - 2 * x;
            if (rem < 0) continue;
            int left = startPos - rem;

            int l = lower_bound(pos.begin(), pos.end(), left) - pos.begin();
            int r = upper_bound(pos.begin(), pos.end(), right) - pos.begin();
            ans = max(ans, preSum[r] - preSum[l]);
        }

        return ans;
    }
};
