class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();;
        int ind = n-1;
        for(int i = n-1; i>0;i--){
            if(nums[i] + i >= ind){
                ind = i;
            }
        }
        return nums[0]>=ind;
    }
};