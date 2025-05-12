class Solution {
public:
    int minOperations(vector<int>& arr) {
        map<int, vector<int>> mpp;
        int mini = 1e9;

        for (int i = 0; i < arr.size(); i++) {
            mpp[arr[i]].push_back(i);
            mini = min(mini, arr[i]);
        }

        set<int> st;
        for (auto x : mpp[mini]) {
            st.insert(x);
        }
        int ans = 0;
       if(mini != 0) ans++;
        mpp.erase(mini);

        for (auto& [val, vec] : mpp) {
            auto it = st.upper_bound(vec[0]);
            st.insert(vec[0]);
            ans++;
            
            int next = *it;

            for (int i = 1; i < vec.size(); i++) {
                st.insert(vec[i]);
                if(it == st.end()) {
                        continue;
                }
                if(vec[i] > *it){
                    ans++;
                    it = st.upper_bound(vec[i]);
                }
            }
        }

        return ans;
    }
};
