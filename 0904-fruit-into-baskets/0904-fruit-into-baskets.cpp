class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n = arr.size();
        int j = 0 ;
        int ans = 0;
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
            
            while(mpp.size() > 2){
                cout<<"size  "<<mpp.size()<< "   "<<i<<endl;
                mpp[arr[j]]--;
                j++;
                if(mpp[arr[j-1]] == 0){
                    mpp.erase(arr[j-1]);
                    break;
                }
            }
            
            if(mpp.size() <= 2){
                ans = max(ans, i-j+1);
            }
            //cout<<j<<" "<< i << "    len = " << i-j+1 <<  "      " <<mpp.size()<<endl;
        }
        return ans;
    }
};