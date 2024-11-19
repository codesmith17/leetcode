class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size();
        unordered_map<int, int> mp;

        while (j < n) {
            mp[nums[j]]++;

            if (mp[nums[j]] > 1)
                return true;

            if (j - i + 1 > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }

            j++;
        }

        return false;
    }
};
