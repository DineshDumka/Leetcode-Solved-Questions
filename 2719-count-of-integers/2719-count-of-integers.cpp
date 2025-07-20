class Solution {
public:
    const int mod = 1e9 + 7;
    //states:  level , tlo, thi , sum
    int dp[23][2][2][400];
    int len;
    int rec(int level , int tlo , int thi, int sum, string num1, string num2, int min_sum, int max_sum){
        if(level == len){
            return (sum>=min_sum && sum<=max_sum);
        }
        if(sum > max_sum) return 0;
        if(dp[level][tlo][thi][sum] != -1) return dp[level][tlo][thi][sum];
        int ans = 0;
        int lo = 0 , hi = 9;
        if(tlo == 1) lo = num1[level] - '0';
        if(thi == 1) hi = num2[level] - '0';
        for(int i=lo;i<=hi;i++){
            int ntlo = tlo, nthi = thi;
            if(i != num1[level] - '0') ntlo = 0;
            if(i != num2[level] - '0') nthi = 0;
            sum += i;
            ans += rec(level + 1, ntlo , nthi , sum, num1, num2, min_sum , max_sum);
            sum -= i;
        }
        return dp[level][tlo][thi][sum] = ans;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        int cnt = num2.length() - num1.length();
        string t = "";
        for(int i=0;i<cnt;i++)t += '0';
        num1 = t + num1;
        len = num2.size();
        memset(dp, -1, sizeof(dp));
        return rec(0 , 1 , 1 , 0, num1, num2, min_sum , max_sum);
    }
};