class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int,int>mpp;
        
        for(auto x : basket1) mpp[x]++;
        for(auto x : basket2) mpp[x]--;

        vector<int>arr;
        int mini = 1e9;
        for(auto&[x,y] : mpp){
            if(y & 1) return -1;
            else{
                for(int i=0;i<abs(y)/2;i++)arr.push_back(x);
            }
            mini = min(mini , x);
        }
        long long ans = 0;
        sort(arr.begin() , arr.end());
        for(int i=0;i<arr.size()/2;i++){
            ans += min(arr[i] , 2*mini);
        }
        return ans;
    }
};