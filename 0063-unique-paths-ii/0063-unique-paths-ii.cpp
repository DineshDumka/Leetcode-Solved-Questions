class Solution {
public:
    int solve(vector<vector<int>>& arr, vector<vector<int>>& dp, int i, int j){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(arr[i][j]==1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int l = solve(arr, dp , i, j-1);
        int u = solve(arr, dp , i-1, j);
        return dp[i] [j] = l+u;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n = arr.size() , m = arr[0].size();
        if(arr[n-1][m-1]==1 || arr[0][0]==1)return 0;
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return solve(arr, dp, n-1, m-1);
    }
};