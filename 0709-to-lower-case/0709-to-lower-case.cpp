class Solution {
public:
    string toLowerCase(string s) {
        string ans = "";
        for(auto x : s){
            if(x >= 'A' && x <= 'Z'){
                x = ('a' + x - 'A') ;
            }
            ans += x;
        }
       // cout<<ans<<endl;
        return ans;
    }
};