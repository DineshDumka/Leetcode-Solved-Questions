class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        multiset<int>ms;
        for(auto x : nums)ms.insert(x);
        int ans = -1;
        for(auto x : nums){
            ms.erase(ms.find(x));
            int y = -1;
            if(!ms.empty())
             y = *ms.rbegin();
            if(y > x)
            ans = max(ans , y - x);
        }
        return ans;
    }
};