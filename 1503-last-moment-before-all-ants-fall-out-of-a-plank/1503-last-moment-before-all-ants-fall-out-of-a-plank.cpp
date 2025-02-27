class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        sort(left.begin(),left.end());
        sort(right.begin(),right.end());
        int l = 0;
        if(left.size()) {
            l = left[left.size()-1] ;
        }
        int r = 0;
        if(right.size()){
            r = n - right[0] ;
        }
        return max(l,r);
    }
};