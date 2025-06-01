class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size() , m = grid[0].size();
        int sr = 0 , sc  = 0 , keys = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] =='@'){
                    sr = i;
                    sc = j;
                }else if(grid[i][j] >='a' && grid[i][j]<='z'){
                    keys++;
                }
            }
        }
        int vis[n][m][1<<keys];
        memset(vis , 0 , sizeof(vis));
        queue<vector<int>>q;
        q.push({sr , sc , 0, 0});
        vis[sr][sc][0]=1;
        while(!q.empty()){
            vector<int> v = q.front(); q.pop();
            int r = v[0], c = v[1] , mask = v[2], moves = v[3];

            if(mask == ((1<<keys) -1)){
                return moves;
            }
            int dx[] = {0,0,-1,1};
            int dy[] = {-1,1,0,0};

            for(int j=0;j<4;j++){
                int x = dx[j]+r;
                int y = dy[j]+c;

                if(x<0 || y<0 ||x>=n || y>=m || grid[x][y]=='#')continue;
                char ch = grid[x][y];
                if(!vis[x][y][mask] && ch>='A' && ch<='Z' && (mask & (1<<(ch - 'A')))){
                    vis[x][y][mask] = 1;
                    q.push({x, y , mask , moves+1});
                }else if(!vis[x][y][mask] && ch>='a' && ch<='z'){
                    int newmask = mask | (1<<(ch - 'a'));
                    vis[x][y][newmask] = 1;
                    q.push({x, y , newmask , moves+1});
                }else if(!vis[x][y][mask] && (ch=='.' || ch=='@')){
                    vis[x][y][mask] = 1;
                    q.push({x, y , mask , moves+1});
                }
            }

        }

        return -1;
    }
};