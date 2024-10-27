class Solution {
private:
    int h(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 or j < 0 or matrix[i][j] == 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int count = 0;
        count += 1 + min({h(matrix, i - 1, j, dp), h(matrix, i - 1, j - 1, dp),
                          h(matrix, i, j - 1, dp)});
        return dp[i][j] = count;
    }

public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),
                               vector<int>(matrix[0].size(), -1));
        int counter = 0;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                if (matrix[i][j] == 1)
                    counter += h(matrix, i, j, dp);

        return counter;
    }
};