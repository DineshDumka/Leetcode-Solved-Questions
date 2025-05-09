class Solution {
public:
    bool detectCapitalUse(string s) {
        int n = s.size();
        bool ans = true;
        if(n==1)return true;
        if(s[0]>='a' && s[0]<='z' && s[1]>='A' && s[1]<='Z')return false;
        for(int i=1;i<n-1;i++){
            if(s[i]>='a' && s[i]<='z' && s[i+1]>='a' && s[i+1]<='z') continue;
            else if(s[i]>='A' && s[i]<='Z' && s[i+1]>='A' && s[i+1]<='A') continue;
            else return false;
        }
        return true;
    }
};