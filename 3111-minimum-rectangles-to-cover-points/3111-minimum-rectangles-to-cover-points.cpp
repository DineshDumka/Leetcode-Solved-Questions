class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        vector<int>arr;
        for(auto x : points){
            arr.push_back(x[0]);
        }
        sort(arr.begin(),arr.end());
        int ans = 0;
        int prev = -1 ;
        for(int i=0;i<arr.size();i++){
            if(prev == -1){
                prev = arr[i];
                ans++;
            } else if(abs(arr[i] - prev) > w){
                prev = arr[i];
                ans++;
            }
        }
        return ans;
    }
};