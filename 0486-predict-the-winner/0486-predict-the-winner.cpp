class Solution {
public:
    bool rec(int s , int e , int turn , int score1, int score2 , int (&dp)[22][22][3], vector<int>& nums){
        //base check
        if(s>e){
            cout<<score1<<" "<<score2<<endl;
            return score1 >= score2;
        }

        if(dp[s][e][turn] != -1)return dp[s][e][turn];
        

        bool ans = false;


        if(turn == 1){
            //take s
            ans |= rec(s+1 , e ,3 - turn,score1 + nums[s] ,score2,dp, nums );

            //take e
             ans |= rec(s , e-1 ,3 - turn,score1 + nums[e] ,score2,dp, nums );

        }else{
            //take s
            if(nums[s] >= nums[e])
            ans |= rec(s+1 , e ,3 - turn,score1 ,score2 + nums[s],dp, nums );
            //take e
            else
             ans |= rec(s , e-1 ,3 - turn,score1 ,score2 + nums[e],dp, nums );
        }


        return dp[s][e][turn] = ans;
    }
    bool predictTheWinner(vector<int>& nums) {
        /*
            dp(startLevel , endLevel  , turn)----> if it is player x turn and
           and array length is from start to end then will he win ?
        */
        int dp[22][22][3];
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        long long score1 = 0 , score2 = 0;
        return rec(0 , n-1 ,1 ,score1 , score2, dp, nums);

    }
};