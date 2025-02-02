class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=1;i<n;i++){
            if(nums[i] < nums[i-1]){
                cnt++;
            }
        }
        if(cnt ==0 ) return true;
        if(cnt== n-1 && n==2) return true;
        if(cnt== n-1 && n==2) return false;
        for(int i=1;i<n;i++){
            if(nums[i] < nums[i-1]){
                reverse(nums.begin(),nums.begin()+i);
                reverse(nums.begin()+i,nums.end());
                reverse(nums.begin(),nums.end());
                break;
            }
        }
        for(int i=1;i<n;i++){
            if(nums[i] < nums[i-1]){
                return false;
            }
        }
        return true;
    }
};