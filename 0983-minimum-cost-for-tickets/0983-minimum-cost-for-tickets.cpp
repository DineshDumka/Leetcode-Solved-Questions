class Solution {
public:
    int rec(int level ,vector<int>& dp ,vector<int>& days, vector<int>& costs){
        int n = days.size();
        if(level >= n){
            return 0;
        }

        if(dp[level] != -1)return dp[level];

        int ans = 1e9;
        //one
        ans = min(ans , costs[0] + rec(level+1 ,dp , days , costs));

        //seven
        int day = days[level] + 6;
        int i = level;
        while(i<n && days[i] <= day) i++;
        ans = min(ans,costs[1] + rec(i ,dp , days , costs));

        //30
         day = days[level] + 29;
         i = level;
        while(i<n && days[i] <= day) i++;
        ans = min(ans,costs[2] + rec(i ,dp , days , costs));
        
        return  dp[level] = ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        /*
        dp(level)----> returns minimum cost to travel from [level-----n]

        TC---> 365
        */
        int n = days.size();
        vector<int>dp(n+1, -1);
        return rec(0 , dp, days, costs);
    }
};