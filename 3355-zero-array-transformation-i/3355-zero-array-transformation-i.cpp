class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>df(n+1 , 0);

        for(auto x : queries){
            int l = x[0], r=  x[1];
            df[l]--;
            df[r+1]++;
        }
        for(int i=1;i<=n;i++){
            df[i] += df[i-1];
        }
        // for(auto x : df)cout<<x<<" ";
        // cout<<endl;

        for(int i=0;i<n;i++){
            nums[i] = nums[i] + df[i];
            if(nums[i] > 0){
                return false;
            }
        }
        // for(auto x : nums)cout<<x<<" ";
        return true;
    }
};