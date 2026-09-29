class Solution {
public:
    int t[101][101][201];
    bool solve(int i, int j, int cntLeft, vector<vector<char>> &grid) {
        cntLeft += (grid[i][j] == '(') ? 1 : -1;
        if (cntLeft < 0) return false;
        int m = grid.size();
        int n = grid[0].size();
        if (i == m - 1 && j == n - 1) {
            return (cntLeft == 0);
        }
        if (t[i][j][cntLeft] != -1) {
            return t[i][j][cntLeft];
        }
        if (i + 1 < m) {
            if (solve(i + 1, j, cntLeft, grid) == true)
                return t[i][j][cntLeft] = true;
        }
        if (j + 1 < n) {
            if (solve(i, j + 1, cntLeft, grid) == true)
                return t[i][j][cntLeft] = true;
        }
        return t[i][j][cntLeft] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int cntLeft = 0;
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }
        if ((m + n - 1) % 2 == 1) {
            return false;
        }
        memset(t, -1, sizeof(t));
        bool ans = solve(0, 0, cntLeft, grid);
        return ans;
    }
};