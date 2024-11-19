class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int i = 0, j = 0, n = nums.size();
        long long sum = 0, res = 0;

        while (j < n) {
            mp[nums[j]]++;
            sum += nums[j];

            if (j - i + 1 == k) {
                if (mp.size() == k)
                    res = max(res, sum);

                mp[nums[i]]--;
                if (mp[nums[i]] == 0) 
                    mp.erase(nums[i]);
                
                sum -= nums[i];
                i++;
            }

            j++;
        }

        return res;
    }
};
