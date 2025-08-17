class Solution {
public:
    void dfs(int r, int c , vector<vector<char>>& grid, vector<vector<int>>&vis){
        int n = grid.size(), 
            m = grid[0].size();

        int x[4] = {0,0,1,-1};
        int y[4] = {-1,1,0,0};
        for(int i=0;i<4;i++){
            int nr = r+x[i] , nc = c+y[i];
            if(nr<0 || nr>=n || nc<0 || nc>= m || grid[nr][nc] == '0' || vis[nr][nc]) continue;
            vis[nr][nc] = 1;
            dfs(nr,nc, grid, vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), 
            m = grid[0].size();
            int ans = 0;
            vector<vector<int>>vis(n , vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    ans++;
                    vis[i][j] = 1;
                    dfs(i , j , grid , vis);
                }
            }
        }
        return ans;
    }
};