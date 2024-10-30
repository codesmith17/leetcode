class Solution {
public:
    // int longestIncreasingSubsequence(vector<int>& vec, int ind, int prevInd,
    //                                  vector<vector<int>>& dp) {
    //     if (ind == vec.size())
    //         return 0;
    //     if (dp[ind][prevInd + 1] != -1)
    //         return dp[ind][prevInd + 1];

    //     int take = 0;
    //     int notTake = longestIncreasingSubsequence(vec, ind + 1, prevInd,
    //     dp); if (prevInd == -1 or vec[ind] > vec[prevInd])
    //         take = 1 + longestIncreasingSubsequence(vec, ind + 1, ind, dp);

    //     return dp[ind][prevInd + 1] = max(take, notTake);
    // }
    vector<int> longestIncreasingSubsequence(vector<int>& vec) {
        if (vec.empty())
            return {};

        vector<int> dp(vec.size(), 1);
        int maxLen = 1;

        for (int i = 1; i < vec.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (vec[i] > vec[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return dp;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftLIS(n, 1);
        vector<int> rightLIS(n, 1);
        leftLIS = longestIncreasingSubsequence(nums);

        reverse(nums.begin(), nums.end());
        rightLIS = longestIncreasingSubsequence(nums);
        reverse(rightLIS.begin(), rightLIS.end());
        int res = 1e9;
        for (int i = 1; i < n - 1; i++) {
            if (leftLIS[i] > 1 && rightLIS[i] > 1) {
                int mountainLength = leftLIS[i] + rightLIS[i] - 1;
                res = min(res, n - mountainLength);
            }
        }

        return res == 1e9 ? 0 : res;
    }
};