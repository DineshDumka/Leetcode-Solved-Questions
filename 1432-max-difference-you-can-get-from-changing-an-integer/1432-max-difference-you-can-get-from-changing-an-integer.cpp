class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string t = s;
        char ch = s[0];
        for(int i=0;i<s.size();i++){
            if(ch=='9' && s[i] != ch){
                ch = s[i];
                s[i] = '9';
            }else if(s[i] == ch){
                s[i] = '9';
            }
        }
        char c = '1';
        if(t[0] != '1'){
            c = t[0];
            for(auto& x : t){
                if(x == c) x = '1';
            }
        }else{
            for(auto x : t){
                if(x != t[0] && x != '0'){
                    c = x;
                    break;
                }
            }
            if( c != '1'){
                for(auto& x : t){
                    if(x == c) x = '0';
                 }
            }
        }

        
       
        int a = stoi(s) , b = stoi(t);
        cout<<a<<" "<<b<<endl;
        return a - b;
        

    }
};