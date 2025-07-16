class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int a, b , c ,d;
        a = b = c = d = 0;
        // all mod 1
        for(auto x  : nums) if(x&1)a++;
        //all mod 0
        for(auto x  : nums) if(!(x&1))b++;
        // 0 - 1 alternale sequence
        int mod = 0;
        for(auto x : nums){
            if(x%2 == mod){
                c++;
                mod ^= 1;
            }
        }
    // 0 - 1 alternale sequence
        mod = 1;
        for(auto x : nums){
            if(x%2 == mod){
                d++;
                mod ^= 1;
            }
        }
        return max({a,b,c,d});
        
    }
};