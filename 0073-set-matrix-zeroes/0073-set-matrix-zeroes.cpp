class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int n = arr.size() , m = arr[0].size();
        vector<int>r(n,1), c(m, 1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==0){
                    r[i] = 0;
                    c[j] = 0;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(r[i]==0 || c[j]==0){
                    arr[i][j] = 0;
                }
            }
        }
       
    }
};