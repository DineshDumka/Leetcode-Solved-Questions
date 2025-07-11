class Solution {
public:
    bool check(int x , int n , int ind, int maxSum){
        int val = x;
        long long sum = 0;
        for(int i=ind;i<n;i++){
            if(val>1){
                sum += val--;
            }else sum += val;
        }
        val = x;
        if(val>1)val--;
        for(int i=ind-1;i>=0;i--){
            if(val>1) sum += val--;
            else sum += val;
        }
        return sum <= (maxSum * 1LL);
    }
    int maxValue(int n, int index, int maxSum) {
        int low = 1 , high = 1e9;
        int ans = -1;
        while(low<=high){
            int mid = (low + high)/2;
            if(check(mid, n, index , maxSum)){
                ans = mid;
                low = mid+1;
            }else high = mid -1;
        }
        return ans;
    }
};