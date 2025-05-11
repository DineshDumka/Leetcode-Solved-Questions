class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<long long> ver(n);
        vector<long long> hor(m);

        for(int i = 0; i < n; i++) {
            long long sum = 0;
            for(int j = 0; j < m; j++) {
                sum += grid[i][j];
            }
            ver[i] = sum;
        }

        for(int i = 0; i < m; i++) {
            long long sum = 0;
            for(int j = 0; j < n; j++) {
                sum += grid[j][i];
            }
            hor[i] = sum;
        }

        vector<long long> pfv(n), sfv(n), pfh(m), sfh(m);
        pfv[0] = ver[0];
        for(int i = 1; i < n; i++) {
            pfv[i] = pfv[i - 1] + ver[i];
        }

        pfh[0] = hor[0];
        for(int i = 1; i < m; i++) {
            pfh[i] = pfh[i - 1] + hor[i];
        }

        sfv[n - 1] = ver[n - 1]; 
        for(int i = n - 2; i >= 0; i--) {
            sfv[i] = sfv[i + 1] + ver[i];
        }

        sfh[m - 1] = hor[m - 1];
        for(int i = m - 2; i >= 0; i--) {
            sfh[i] = sfh[i + 1] + hor[i];
        }

        for(int i = 0; i < n - 1; i++) {
            if(pfv[i] == sfv[i + 1]) {
                return true;
            }
        }

        for(int i = 0; i < m - 1; i++) {
            if(pfh[i] == sfh[i + 1]) {
                return true;
            }
        }

        return false;
    }
};
