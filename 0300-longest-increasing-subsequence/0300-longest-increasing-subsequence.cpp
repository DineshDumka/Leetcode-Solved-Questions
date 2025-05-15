class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        for(auto x : nums){
            if(ans.empty()){
                ans.push_back(x);
            }else if(x > ans.back()){
                ans.push_back(x);
            }else{
                auto lb = lower_bound(ans.begin() ,ans.end() , x) ;
                *lb = x;
            }
        }
        return ans.size();
    }
};