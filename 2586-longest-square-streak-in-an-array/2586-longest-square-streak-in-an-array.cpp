class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int root = sqrt(nums[i]);
            if (root * root != nums[i]) {
                mp[nums[i]] = 1;
            } else {
                if (mp.find(root) != mp.end()) {
                    mp[nums[i]] = mp[root] + 1;
                } else {
                    mp[nums[i]] = 1;
                }
            }
        }
        int maxi = 1;
        for (auto it : mp)
        {
            maxi = max(maxi, it.second);
        }
        return (maxi == 1) ? (-1) : maxi;
    }
};