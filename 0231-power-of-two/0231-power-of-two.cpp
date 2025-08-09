class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return 0;
        if(n == INT_MIN) return true;
        return !(n&(n-1));
    }
};