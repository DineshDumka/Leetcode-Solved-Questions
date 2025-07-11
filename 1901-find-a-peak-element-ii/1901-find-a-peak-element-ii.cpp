class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        int i = 0 , j = 0;
        while(true){
            int maxi = i, maxj = j;
            if(i-1 >= 0 && mat[maxi][maxj] < mat[i-1][j]){
                maxi = i-1;
                maxj = j;
            }
            if(i+1 < n && mat[maxi][maxj] < mat[i+1][j]){
                maxi = i+1;
                maxj = j;
            }
            if(j-1>=0 && mat[maxi][maxj] < mat[i][j-1]){
                maxi = i;
                maxj = j-1;
            }
            if(j+1<m && mat[maxi][maxj] < mat[i][j+1]){
                maxi = i;
                maxj = j+1;
            }
            if(maxi==i && maxj==j)break;
            i = maxi ;
            j = maxj;
        }
        bool flag = true;
        if(i-1>=0 && mat[i][j]<mat[i-1][j])flag = false;
        if(i+1<n && mat[i][j]<mat[i+1][j])flag = false;
        if(j-1>=0 && mat[i][j]<mat[i][j-1])flag = false;
        if(j+1<m && mat[i][j]<mat[i][j+1])flag = false;
        if(flag) return {i,j};
        return {-1,-1};
    }
};