class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> prefix = {1};
        int n = nums.size();
        for (int i = 1; i < n; i++)
            prefix.push_back((nums[i] == nums[i - 1] + 1) ? prefix.back() + 1
                                                          : 1);
        vector<int> res;
        for (int i = k - 1; i < n; i++)
            res.push_back(prefix[i] >= k ? nums[i] : -1);
        return res;
    }
};