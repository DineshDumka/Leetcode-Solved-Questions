class Solution {
public:
    int maxDistance(string str, int k) {
        int e = 0 , w = 0 , n = 0 , s = 0;
        int ans = 0;
        for(auto x : str){
            if(x=='N')n++;
            else if(x == 'E')e++;
            else if(x == 'W')w++;
            else s++;

            int t1 = min({n , s ,k});
            int t2 = min({e , w , k - t1});
            int val1 = abs(n-s)+t1*2;
            int val2 = abs(e-w)+t2*2;
            ans = max(ans ,val1+val2 );
        }
        return ans;
    }
};