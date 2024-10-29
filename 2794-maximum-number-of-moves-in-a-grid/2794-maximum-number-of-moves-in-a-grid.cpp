class Solution {
public:
    int recursion(vector<vector<int>>& grid, int n, int m,
                  vector<vector<int>>& dp, int i, int j, int prev) {

        if (i < 0 or i >= n or j >= m or grid[i][j] <= prev)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int topRight = recursion(grid, n, m, dp, i - 1, j + 1, grid[i][j]);
        int right = recursion(grid, n, m, dp, i, j + 1, grid[i][j]);
        int bottomRight = recursion(grid, n, m, dp, i + 1, j + 1, grid[i][j]);

        return dp[i][j] = 1 + max({topRight, right, bottomRight});
    }

    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int res = 0;

        for (int i = 0; i < n; i++) {
            res = max(res, recursion(grid, n, m, dp, i, 0, 0));
        }

        return res - 1;
    }
};
