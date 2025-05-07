class Solution {
public:
    bool check(int r, int c, vector<string>& arr, vector<int>& queens) {
        for (int row = 0; row < r; row++) {
            int col = queens[row];
            if (col == c || abs(row - r) == abs(col - c)) {
                return false;
            }
        }
        return true;
    }

    void rec(int n, vector<vector<string>>& ans, vector<int>& queens, int row, vector<string>& arr) {
        if (row == n) {
            vector<string> v = arr;
            ans.push_back(v);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (check(row, col, arr, queens)) {
                arr[row][col] = 'Q';
                queens[row] = col;
                rec(n, ans, queens, row + 1, arr);
                arr[row][col] = '.';
                queens[row] = -1;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> arr(n, string(n, '.'));
        vector<int> queens(n, -1);
        rec(n, ans, queens, 0, arr);
        return ans;
    }
};
