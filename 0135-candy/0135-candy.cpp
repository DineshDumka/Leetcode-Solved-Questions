class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>arr(n , 1);
        for(int i=0;i<n;i++){
            if(i+1 < n && ratings[i+1] > ratings[i]) arr[i+1] = arr[i] + 1;
        }
        for(int i=n-1;i>=0;i--){
            if(i-1 >=0 && ratings[i-1] > ratings[i] && arr[i-1] <= arr[i]) arr[i-1] = arr[i]+1;
        }
        int ans = 0;
        for(auto x : arr) ans += x;
        return ans;
    }
};