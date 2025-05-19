class Solution {
public:
    int rec(int level , vector<int>& nums, vector<int>&dp){
        int n = nums.size();
        if(level >= n-1){
            return 0;
        }
        if(dp[level] != -1){
            return dp[level];
        }
        int ans = 1e9;
        for(int i=1;i<=nums[level];i++){
            ans = min(rec(level+i, nums, dp)+1, ans);
        }

        return dp[level] = ans;

    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        return rec(0 , nums, dp);
    }
};