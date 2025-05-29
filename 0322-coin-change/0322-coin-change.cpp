class Solution {
public:
    int rec(int level ,int amount ,vector<vector<int>>& dp, vector<int>& coins){
        int n = coins.size();
        //pruning
        if(amount == 0) return 0;
        //base case
        if(level == n){
            if(amount == 0) return 0;
            return 1e9;
        }
        
        //cache check
        if(dp[level][amount] != -1)return dp[level][amount];

        int ans = 1e9;

        if(coins[level] <= amount){
            ans = min(ans , 1 + rec(level , amount - coins[level] ,dp , coins));
        }else{
            ans = min(ans , rec(level + 1 , amount  ,dp , coins));
        }

        return dp[level][amount] = ans;

    }
    int coinChange(vector<int>& coins, int amount) {
        /*
            dp( i(level) , x(moneyneeded)) -----> returns if i am at level i and have
            needed x money then how much  minimum coins i need to get that
            money from [level+1 ----- n]

            TC --- >   #s = 12 * 1e4 ~ 1e5 ---->   coins.size()  * amount
                        #t  = 2
                        tc = 1e5
            sc -----> dp  --> coins.size()  * amount   and recursion stack space
        */
        sort(coins.rbegin() , coins.rend());
        vector<vector<int>> dp(coins.size() + 1 , vector<int>(amount + 1 , -1));
        int ans =  rec(0 , amount ,dp ,  coins);
        if(ans == 1e9) return -1;
        return ans;

    }
};