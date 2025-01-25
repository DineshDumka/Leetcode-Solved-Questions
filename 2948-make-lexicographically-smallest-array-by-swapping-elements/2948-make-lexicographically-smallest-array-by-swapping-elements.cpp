class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> vp;
        for(int i=0;i<nums.size();i++){
            vp.push_back({nums[i],i});
        }
        sort(vp.begin(),vp.end());
        vector<vector<pair<int,int>>> groups;
        groups.push_back({vp[0]});
        for(int i=1;i<vp.size();i++){
            if(vp[i].first - vp[i-1].first <= limit){
                groups.back().push_back({vp[i]});
            }
            else{
                groups.push_back({vp[i]});
            }
        }

        for(auto group : groups){
            vector<int> ind;
            for(auto [val, i] : group){
                ind.push_back(i);
            }
            sort(ind.begin(),ind.end());
            for(int i=0;i<ind.size();i++){
                nums[ind[i]] = group[i].first;
            }
        }
        return nums;
    }
};