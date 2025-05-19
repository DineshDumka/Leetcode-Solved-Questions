class Solution {
public:
    long long rec(int level, vector<vector<int>>& rides, vector<long long>& dp, vector<int>& starts) {
        int size = rides.size();
        //base case
        if (level == size) return 0;
        //cache check
        if (dp[level] != -1) return dp[level];

        int start = rides[level][0];
        int end = rides[level][1];
        int tip = rides[level][2];

        
        int ind = lower_bound(starts.begin(), starts.end(), end) - starts.begin();

        // Take 
        long long take = (end - start) + tip + rec(ind, rides, dp, starts);

        // Skip 
        long long skip = rec(level + 1, rides, dp, starts);
        //save and return
        return dp[level] = max(take, skip);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());  

        vector<int> starts;
        for (auto &ride : rides) {
            starts.push_back(ride[0]);
        }

        vector<long long> dp(rides.size(), -1);
        return rec(0, rides, dp, starts);
    }
};
