class Solution {
public:
    long long distributeCandies(int n, int limit) {
        int m = min(n , limit);
        long long ans = 0;
        for(int i=0;i<=m;i++){
            int l  = max(0, n - i - limit);
            int r = min(limit, n - i);
            if(r-l+1 > 0)
                ans += (r-l+1);
        }
        return ans;
    }
};