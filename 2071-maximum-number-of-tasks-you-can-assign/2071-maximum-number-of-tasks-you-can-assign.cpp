class Solution {
    bool canAssign(int mid, vector<int>& workers, vector<int>& tasks, int pills, int strength) {
        multiset<int> usable_workers(workers.end() - mid, workers.end());

        for (int i = mid - 1; i >= 0; --i) {
            auto it = prev(usable_workers.end());

            if (*it >= tasks[i]) {
                usable_workers.erase(it);
            } else {
                if (pills == 0) return false;

                // Find the weakest worker who can complete task[i] using a pill
                auto it2 = usable_workers.lower_bound(tasks[i] - strength);
                if (it2 == usable_workers.end()) return false;

                usable_workers.erase(it2);
                pills--;
            }
        }
        return true;
    }

public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int low = 0, high = min(tasks.size(), workers.size());
        int result = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canAssign(mid, workers, tasks, pills, strength)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
};
