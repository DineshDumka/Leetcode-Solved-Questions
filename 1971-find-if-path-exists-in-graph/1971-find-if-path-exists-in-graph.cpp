class Solution {
public:
    bool dfs(int i , int d , vector<vector<int>>& g, vector<int>& vis){
        if(i >= vis.size()) return false;
        if(i == d) return true;

        bool ans = false;
        for(auto v : g[i]){
            if(!vis[v]){
                vis[v] = 1;
                ans |= dfs(v , d, g, vis);
            }
        }
        return ans;

    }
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        vector<vector<int>> g(n+1, vector<int>());
        vector<int>vis(n+1, 0);
        
        for(auto x : edges){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        bool ans = false;
        for(int i=1; i<=n;i++){
            if(!vis[i])
            ans |= dfs(s, d , g, vis);
        }
        return ans;
    }
};