class Solution {
public:
    void dfs(int v, vector<int>& vis, vector<int>& pathVis, stack<int>& st, vector<vector<int>>& adj, bool& loop){
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
        st.push(v);
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
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
            if(loop) return{};
        }

        vector<int>ans;
        if(prerequisites.size()==0) {
            for(int i=n-1;i>=0;i--) ans.push_back(i);
            return ans;
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};