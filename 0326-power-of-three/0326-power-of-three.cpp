class Solution {
public:
    bool isPowerOfThree(int n) {
        long long curr = 1;
        while(true){
            if(n==curr) {
                return true;
            }
            if(curr > n) return false;
            curr *= 3;
        }
        return true;
    }
};