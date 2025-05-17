class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z= 0 , o = 0 , t = 0;
        for(auto x : nums){
            if(x == 0)z++;
            else if(x == 1) o++;
            else t++;
        }
        for(auto &x : nums){
            if(z){
                x = 0;
                z--;
            }else if(o){
                x = 1;
                o--;
            }else{
                x = 2;
                t--;
            }
        }
        
    }
};