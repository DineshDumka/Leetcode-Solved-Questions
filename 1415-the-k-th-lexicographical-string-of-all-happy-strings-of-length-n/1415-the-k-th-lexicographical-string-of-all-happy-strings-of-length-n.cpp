class Solution {
public:
    void solve(string& s, string curr, int n, int& k, string& result) {
        if(result != "") return;
        if (curr.size() == n) { 
            k--; 
            if (k == 0) result = curr; 
            return;
        }

        for (char ch : s) { 
            if (curr.empty() || ch != curr.back()) { 
                solve(s, curr + ch, n, k, result);
                if (k == 0) return; 
            }
        }
    }

    string getHappyString(int n, int k) {
        string s = "abc"; 
        string result = ""; 
        solve(s, "", n, k, result); 
        return result;
    }
};
