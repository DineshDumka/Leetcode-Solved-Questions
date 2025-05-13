class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        left--;
        right--;
       
        int M = 1e9+7;
        vector<int>arr;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum = (sum + nums[j])%M;
                arr.push_back(sum);
            }
        }
        sort(arr.begin() ,arr.end());
        int ans = 0;
        for(int i=left;i<=right;i++){
            ans = (ans + arr[i])%M;
        }
        return ans;
    }
};