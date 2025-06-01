class Solution {
public:
    int bfs(int i , vector<vector<int>>& graph){
        int n = graph.size();
        vector<vector<int>> vis( n , vector<int>((1<<n), 0));
        queue<vector<int>>q;
        q.push({i, (1<<i) , 0});
        vis[i][1<<i] = 1;
        
        while(!q.empty()){
            vector<int> v = q.front(); q.pop();
            int node = v[0];
            int mask = v[1];
            int moves = v[2];

            if(mask == (1<<(n))-1) {
                return moves;
            }

            for(auto neigh : graph[node]){
                if(!vis[neigh][mask]){
                    vis[neigh][mask] = 1;
                    int newmask = mask | (1<<neigh);
                    q.push({neigh ,newmask , moves+1 });
                }
            }
        }
        return -1;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int ans = 1e9;
        for(int i=0;i<n;i++){
            //if(!vis[i][(1<<i)]){
              //  vis[i][(1<<i)] = 1;
                ans = min(ans , bfs(i ,graph));
           // }
        }
        return ans;
    }
};