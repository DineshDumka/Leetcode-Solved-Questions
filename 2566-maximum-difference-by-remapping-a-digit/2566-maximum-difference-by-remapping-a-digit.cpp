class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string t = s;
        char ch = s[0];
        int n = s.size();
        
        for(int i=0;i<n;i++){
            if(s[i] != ch && ch == '9'){
                ch = s[i];
                s[i] = '9';
            }else if(s[i]== ch){
                s[i] = '9';
            }
        }
        
        char c = t[0];
        for(int i=0;i<n;i++){
            if(t[i]== c){
                t[i] = '0';
            }
        }
        int a = stoi(s);
        int b = stoi(t);
        return a - b;

    }
};