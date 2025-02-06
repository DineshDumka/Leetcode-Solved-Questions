class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(), m = graph[0].size();
        vector<int> vis(n,0);
        vector<int>clr(n,-1);
        // {{node parent} , color}
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                q.push({{i,-1},0});
                clr[i] = 0;
                vis[i] = 1;
                while(!q.empty()){
                    pair<pair<int,int>,int> p = q.front();
                    q.pop();
                    int node = p.first.first;
                    int parent = p.first.second;
                    int color = p.second;
                    for(auto x : graph[node]){
                        if(!vis[x]){
                            vis[x] = 1;
                            if(color==0){
                                q.push({{x,node},1});
                                clr[x] = 1;
                            }
                            else{
                                 q.push({{x,node},0});
                                 clr[x] = 0;
                            }
                        }
                        else if(parent != x && clr[x] == clr[node]) return false;
                    }
                }
            }
        }
        return true;
    }
};