class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        /*
             1,2,3,4,5,10,6,7,8,9
        %5 ->1 2 3 4 0  0 1 2 3 4

           pair ===  k-arr[i]%k , arr[i]%k
        */
        int n = arr.size();
        map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            arr[i] = ((arr[i] %k) +k)%k;
            mpp[arr[i]]++;
        }
        if(mpp.find(0) != mpp.end() && mpp[0]&1) return false;
        for(int i=1;i<k;i++){
            if(mpp[i] != mpp[k - i])return false;
        }
        return true;
    }
};