class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        stack<pair<int, int>> stk;
                // val , ind
        int n = arr.size();
        vector<int>ans(n);
        for(int i=n-1; i>=0;i--){
            while(!stk.empty()){
                int val = stk.top().first;
                int ind = stk.top().second;
                if(val <= arr[i]) {
                    stk.pop();
                }else break;
            }
            if(stk.empty()){
                ans[i] = i;
            }else{
                ans[i] = stk.top().second;
            }
            stk.push({arr[i] , i});
        }
        for(int i=0;i<n;i++){
            ans[i] -= i;
        }
        return ans;
    }
};