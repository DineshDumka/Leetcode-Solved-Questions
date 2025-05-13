class Solution {
public:
    int captureForts(vector<int>& arr) {
        int ans = 0;
        int m1 = -1 , one = -1;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==-1 && one != -1){
                ans = max(ans , abs(i - one) - 1);
                one = -1;
            }else if(arr[i]==1 && m1 != -1 ){
                ans = max(ans , abs(m1 - i) - 1);
                m1 = -1;
            }
            if(arr[i]==1){
                one = i;
            }
            if(arr[i] == -1){
                m1 = i;
            }
        }
        return ans;
    }
};