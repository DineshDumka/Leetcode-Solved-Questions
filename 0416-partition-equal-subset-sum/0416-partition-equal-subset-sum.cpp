class Solution {
public: 
    int dp[210][110000];
    bool rec(int i , int sum , vector<int>& nums){
        if(sum <0)return false;
        if(sum == 0)return true;
        if(i == nums.size()){
            return sum == 0;
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        bool ans = false;
        //pick
        ans |= rec(i+1 , sum - nums[i] , nums);
        ans |= rec(i+1 , sum , nums);
        return dp[i][sum] = ans;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x : nums)sum += x;
        if(sum &1 )return false;
        memset(dp , -1, sizeof(dp));
        return rec(0 , sum/2, nums);
    }
};