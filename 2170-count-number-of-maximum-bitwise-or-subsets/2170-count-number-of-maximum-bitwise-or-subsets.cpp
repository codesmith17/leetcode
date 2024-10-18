class Solution {
public:
    void recursion(vector<int>& nums, vector<int>& ds, int ind, int n,
                   int& maxOR, unordered_map<int, int> &mp) {
        if (ind == n) {
            int currentOR = 0;
            for (auto it : ds)
                currentOR |= it;
            maxOR = max(maxOR, currentOR);
            mp[currentOR]++;
            return;
        }
        ds.push_back(nums[ind]);
        recursion(nums, ds, ind + 1, n, maxOR, mp);

        ds.pop_back();
        recursion(nums, ds, ind + 1, n, maxOR, mp);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> ds;
        unordered_map<int, int> mp;
        int maxOR = 0;
        recursion(nums, ds, 0, nums.size(), maxOR, mp);
        return mp[maxOR];
    }
};
