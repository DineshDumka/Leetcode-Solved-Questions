class Solution {
public:
    int  rec(int r, vector<vector<int>>& mat, int target, int sum, vector<vector<int>>& dp){
        int n = mat.size() , m = mat[0].size();
        //base
        if(r == n){
            return abs(sum - target);
        }

        //cache check
        if(dp[r][sum] != -1){
            return dp[r][sum];
        }

        //compute
        int ans = 1e9;
        for(int j=0;j<m;j++){
            ans = min(ans , rec(r+1, mat, target , sum+mat[r][j], dp));
        }
        //save and return
        return dp[r][sum] = ans;

    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int maxsum = 4800;
        vector<vector<int>> dp(n+1, vector<int>(maxsum+1, -1));
        return rec(0, mat, target, 0, dp);
        
    }
};