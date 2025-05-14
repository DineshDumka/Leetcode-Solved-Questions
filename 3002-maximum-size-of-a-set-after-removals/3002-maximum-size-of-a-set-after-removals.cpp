class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        set<int> st1, st2;
        for (auto x : nums1) {
            st1.insert(x);
        }
        for (auto x : nums2) {
            st2.insert(x);
        }
        set<int> ans;
        set<int> a;
        set<int> b;
        for (auto x : nums1) {
            if (st2.find(x) == st2.end() && a.size() < n / 2) {
                a.insert(x);
            }
        }
        for (auto x : nums2) {
            if (st1.find(x) == st1.end() && b.size() < n / 2) {
                b.insert(x);
            }
        }
        set<int>common;
        for (auto x : nums1) {
            if (st2.find(x) != st2.end() ) {
                common.insert(x);
            }
        }

        for (auto x : nums2) {
            if (st1.find(x) != st1.end() ) {
                common.insert(x);
            }
        }

        return min(int(a.size() + b.size() + common.size()) , n);
    }
};