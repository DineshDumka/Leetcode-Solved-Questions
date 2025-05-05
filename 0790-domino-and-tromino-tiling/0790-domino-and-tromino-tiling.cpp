class Solution {
public:
    const int mod = 1e9 + 7;
    int numTilings(int n) {
        vector<int>arr(10000);
        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 5;
        for(int i = 4;i<=n;i++){
            arr[i] = ((2*arr[i-1])%mod + arr[i-3])%mod;
        }
        return arr[n];
    }
};