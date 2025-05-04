class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& arr) {
        int cnt =  0, n = arr.size();
        for(int i=0;i<n;i++){
            int a = arr[i][0];
            int b = arr[i][1];
            for(int j=i+1;j<n;j++){
                int c = arr[j][0];
                int d = arr[j][1];
                if(a==c && b==d) cnt++;
                else if(a==d && b==c) cnt++;
            }
        }
        return cnt;
    }
};