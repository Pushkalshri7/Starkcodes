class Solution {
public:
    vector<vector<string>> ans;

    void solve(vector<string>& b, int r, int n) {
        if (r == n) {
            ans.push_back(b);
            return;
        }

        for (int c = 0; c < n; c++) {
            bool ok = true;

            for (int i = 0; i < r; i++)
                if (b[i][c] == 'Q') ok = false;

            for (int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--)
                if (b[i][j] == 'Q') ok = false;

            for (int i = r-1, j = c+1; i >= 0 && j < n; i--, j++)
                if (b[i][j] == 'Q') ok = false;

            if (ok) {
                b[r][c] = 'Q';
                solve(b, r+1, n);
                b[r][c] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> b(n, string(n, '.'));
        solve(b, 0, n);
        return ans;
    }
};