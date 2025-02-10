class Solution {
public:
    void dfs(int v, vector<int>& vis, vector<int>& pathVis, stack<int>st, vector<vector<int>>& adj, bool& loop){
        if(loop) return;
        vis[v] = 1;
        pathVis[v] =1;
        for(auto x : adj[v]){
            if(pathVis[x]) {
                loop = true;
                return;
            }
            if(!vis[x]) dfs(x, vis, pathVis, st, adj, loop) ;
        }
        pathVis[v] = 0;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(n, vector<int>());
        for(auto x : prerequisites){
            adj[x[1]].push_back(x[0]);
        }
        
        vector<int>vis(n,0);
        vector<int>pathVis(n,0);
        stack<int> st;
        bool loop = false;

        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i, vis, pathVis, st, adj, loop);
        }
        return !loop;
    }
};