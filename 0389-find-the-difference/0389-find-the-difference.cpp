class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> fq(26 , 0);
        for(auto x : t){
            fq[x - 'a']++;
        }
        for(auto x : s){
            fq[x - 'a']--;
        }
        for(int i=0;i<26;i++){
            if(fq[i]==1){
                return char(i + 'a');
            }
        }
        return 'a';
    }
};