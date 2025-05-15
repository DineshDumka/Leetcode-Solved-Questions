class Solution {
public:
    string pallindrome(const string& s, int start, int end) {
        while (start >= 0 && end < s.size() && s[start] == s[end]) {
            start--;
            end++;
        }
        return s.substr(start + 1, end - start - 1); // Corrected this line
    }

    string longestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        } 
        
        string max_str = "";
        max_str += s[0];
        
        for (int i = 0; i < s.size(); i++) {
            string odd = pallindrome(s, i, i);
            string even = pallindrome(s, i, i + 1);
            
            if (odd.size() > max_str.size()) {
                max_str = odd;
            }
            if (even.size() > max_str.size()) {
                max_str = even;
            }
        }
        
        return max_str;
    }
};
