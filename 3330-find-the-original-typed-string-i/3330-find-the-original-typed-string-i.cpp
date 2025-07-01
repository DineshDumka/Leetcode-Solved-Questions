class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        map<char , int>mpp;
        for(auto x : word){
            if(mpp.size() == 0){
                mpp[x]++;
            }else{
                if(mpp.find(x) != mpp.end()) mpp[x]++;
                else{
                    for(auto [ch ,y] : mpp)cout<<ch<<" "<<y<<endl;
                    for(auto& [ch, y] : mpp){
                        ans += y-1;
                    }
                    mpp.clear();
                    mpp[x]++;
                }
            }
        }
        for(auto& [ch, y] : mpp){
            ans += y-1;
        }
        
        return ans;
    }
};