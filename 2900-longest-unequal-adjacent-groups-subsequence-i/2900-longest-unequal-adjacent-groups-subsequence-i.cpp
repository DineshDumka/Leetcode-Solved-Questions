class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int cnt = 1;
        int n = words.size() , prev = groups[0];
        vector<string>ans;
        ans.push_back(words[0]);
        for(int i=1;i<n;i++){
            if(groups[i] != prev){
                prev= groups[i];
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};