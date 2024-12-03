class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string t = "";
        int prev = 0;
        for(int i=0;i<spaces.size();i++){
            t += s.substr(prev, spaces[i]-prev);
            prev = spaces[i];
            if(spaces[i] < s.size()) t += " ";
        }
        if(prev < s.size()) t += s.substr(prev, s.size()-prev);
        return t;
    }
};