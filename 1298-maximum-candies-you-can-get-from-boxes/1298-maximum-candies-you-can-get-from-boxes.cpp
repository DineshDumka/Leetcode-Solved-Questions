class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {

        set<int> st;
        for (auto x : initialBoxes)
            st.insert(x);
        int ans = 0;
        unordered_map<int, int> mpp;
        int n = candies.size();
        vector<int> vis(n + 1, 0);
        while (!st.empty()) {
            bool found = false;
            for (auto x : st) {
                if (status[x] == 0 && mpp[x] != 0) {
                     /*
                     it is close but i have a key
                     noow i am inside box and i will collect the keys inside
                     it and boxes if not visited
                     */
                     found = true;
                     vis[x] = 1;
                     mpp[x] = 0;
                     for(auto k : keys[x])mpp[k] = 1;
                     for(auto b : containedBoxes[x]){
                        if(!vis[b])st.insert(b);
                     }
                     ans += candies[x];
                     st.erase(x);

                } else if(status[x] == 1) {// it is open and you can go inside it 
                    found = true;
                    vis[x] = 1;
                    for(auto k : keys[x])mpp[k] = 1;
                     for(auto b : containedBoxes[x]){
                        if(!vis[b])st.insert(b);
                     }
                     ans += candies[x];
                     st.erase(x);
                }
            }
            if(!found)break;
        }
        return ans;
    }
};