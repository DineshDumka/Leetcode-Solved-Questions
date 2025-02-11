class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.size(), m = part.size();
        if(n<m) return s;
        while(true){
            if(s.find(part) != -1){
                s.erase(s.find(part), part.size());
            }else break;
            if(s.size()<m) break;
        }
        return s;
    }
};