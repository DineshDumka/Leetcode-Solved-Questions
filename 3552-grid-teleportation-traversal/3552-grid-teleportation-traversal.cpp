using state = pair<int,int>;

class Solution {
public:
    int minMoves(vector<string>& arr) {
        if(arr[0][0] == '#') return -1;
        int  n = arr.size() , m = arr[0].size();
        map<char , vector<state>>mpp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch = arr[i][j];
                if(ch>='A' && ch<='Z'){
                    mpp[ch].push_back({i,j});
                }
            }
        }

        vector<vector<int>>dist(n , vector<int>(m , 1e9));
        deque<state>dq;
        
        dist[0][0] = 0;
        dq.push_back({0,0});

        while(!dq.empty()){
            state s = dq.front();
            dq.pop_front();
            int r = s.first;
            int c = s.second;

            if(arr[r][c] != '.' ){
                char ch = arr[r][c];
                for(auto&[i,j] : mpp[ch]){
                    if( dist[i][j] > dist[r][c]){
                        dist[i][j] =  dist[r][c];
                        dq.push_front({i,j});
                    }
                }
            }

            int dx[] = {0,0,-1,1};
            int dy[] = {-1,1,0,0};

            for(int j = 0; j<4;j++){
                int x = dx[j] + r;
                int y = dy[j] + c;
                if(x<0 || y<0 || x>=n || y>=m || arr[x][y] == '#'){
                    continue;
                }else if(dist[x][y] > dist[r][c] + 1){
                    dist[x][y] = dist[r][c] + 1;
                    dq.push_back({x,y});
                }
            }

        }
        if(dist[n-1][m-1] == 1e9){
            return -1;
        }else{
            return dist[n-1][m-1];
        }

    }
};