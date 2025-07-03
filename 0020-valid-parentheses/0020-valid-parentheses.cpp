class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(auto x :s){
            if(x == '(' || x=='{' || x == '['){
                stk.push(x);
            }else if(x == ')'){
                if(stk.empty()) return false;
                if(stk.top() == '(') stk.pop();
                else return false;
            }else if(x == '}'){
                if(stk.empty()) return false;
                if(stk.top() == '{') stk.pop();
                else return false;
            }else if(x == ']'){
                if(stk.empty()) return false;
                if(stk.top() == '[') stk.pop();
                else return false;
            }
        }
        
        return stk.empty();
    }
};

// ([)]