class Solution {
public:
    long long appealSum(string s) {
        long long n = s.size();
        long long ans = 0;
        
        for(auto ch = 'a';ch<='z';ch++){
            int prev = -1;
            bool present  = false;
            long long cont = ((n+1)*n/2);
            for(int i=0;i<n;i++){
                if(s[i]==ch){
                    present = true;
                    long long len = i-prev;
                    cont -= ((len)*(len-1))/2;
                    prev = i;
                }
            }
            long long len = n-prev;
            cont -= ((len)*(len-1))/2;
            
            if(present)ans += cont;
        }
        return ans;
    }
};