class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int n = arr.size() , m = arr[0].size();
        int fr= 1, fc = 1;
        if(arr[0][0] == 0){
            fr= 0; fc= 0;
        }

        for(int i=1;i<n;i++){
            if(arr[i][0]==0)fc = 0;
        }
        for(int i=1;i<m;i++){
            if(arr[0][i]==0)fr = 0;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(arr[i][j] == 0){
                    arr[i][0] = 0;
                    arr[0][j] = 0;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(arr[i][0]==0 || arr[0][j] == 0){
                    arr[i][j]=0;
                }
            }
        }
        for(int i = 0;i<n;i++){
             if(fc == 0)   arr[i][0] = 0;          
         }   
        for(int j=0;j<m;j++){
            if(fr == 0) arr[0][j] = 0;
        }
        if(fr ==0 || fc==0){
            arr[0][0] = 0;
        }
       
    }
};