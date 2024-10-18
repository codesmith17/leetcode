class Solution {
public:
    void recursion(vector<int>& nums, vector<int>& ds, int ind, int n,
                   int& maxOR, vector<int>& res) {
        if (ind == n) {
            int currentOR = 0;
            for (auto it : ds) 
                currentOR |= it;
            maxOR = max(maxOR, currentOR);
            res.push_back(currentOR);
            return;
        }
        ds.push_back(nums[ind]);
        recursion(nums, ds, ind + 1, n, maxOR, res);

        ds.pop_back();
        recursion(nums, ds, ind + 1, n, maxOR, res);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> ds, res;
        int maxOR = 0;
        recursion(nums, ds, 0, nums.size(), maxOR, res);
        int cnt = 0;
        for (auto it : res) 
            cnt += it == maxOR;
        
        return cnt;
    }
};
