class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int val = -1e9;
        for(int i=0;i<num.size()-2;i++){
            string t = "";
            t += num[i];
            t += num[i+1];
            t += num[i+2];
            int n = stoi(t);
            if(n>val && t[0]==t[1] && t[1] == t[2]){
                ans = t;
                val = n;
            }
        }
        return ans;
    }
};