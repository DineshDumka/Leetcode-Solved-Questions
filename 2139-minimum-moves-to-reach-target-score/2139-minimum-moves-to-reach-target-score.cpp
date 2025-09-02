class Solution {
public:
    int minMoves(int target, int maxDoubles){
        int odd = 0;
        int cnt = 0;
        while(target > 1 && cnt < maxDoubles){
            if(target & 1){
                odd++;
                target--;
            }else {
                target /= 2;
                cnt++;
            }
        }
        int ans = target - 1 + odd + cnt;
        return ans;
    }
};