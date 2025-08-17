class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>arr(n+1);
        arr[0] = 0;
        for(int i=1;i<=n;i++) arr[i] = nums[i-1];
        
        vector<long long>pf(n+1, 0);
        for(int i=1;i<=n;i++){
            pf[i] += pf[i-1];
            pf[i] += arr[i];
        }
        int i = 1 , j = 2;
        int ans = 1;
        while(j<=n){
            long long sum = 1LL*arr[j] * (j-i+1);
            long long val = pf[j] - pf[i-1];
            long long total = sum - val;
            if(total > k){
                i++;
            }else j++;
            ans = max(ans , j-i);
        }
        //cout<<i<<" "<<j<<endl;
        return ans;
    }
};