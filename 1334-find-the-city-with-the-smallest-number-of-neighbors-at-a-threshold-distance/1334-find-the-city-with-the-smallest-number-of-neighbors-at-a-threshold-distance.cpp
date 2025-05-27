class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n , vector<int>(n , 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i != j) dist[i][j] = 1e9;
            }
        }
        for(int i=0;i<edges.size();i++){
            int a = edges[i][0] , b = edges[i][1], c = edges[i][2];
            dist[a][b] = min(dist[a][b] , c);
            dist[b][a] = min(dist[b][a] , c);
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j =0;j <n; j++){
                    dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
                }
            }
        }

        int ans = 0;
        int mincnt = 1e9;
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(i != j && (dist[i][j] <= distanceThreshold)) cnt++;
              //  cout<<dist[i][j]<<" ";
            }
           // cout<<endl;
            //cout<<mincnt<<endl;
            if(cnt <= mincnt){
                mincnt = cnt;
                ans = i;
            }
        }
        return ans;
    }
};