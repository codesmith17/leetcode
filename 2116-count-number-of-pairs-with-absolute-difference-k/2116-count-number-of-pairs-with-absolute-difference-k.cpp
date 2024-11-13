class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int cnt = 0;
        for (int& it : nums) {
            int complement1 = k + it;
            int complement2 = -k + it;
            if (mp.find(complement1) != mp.end())
                cnt += mp[complement1];
            if (complement1 != complement2)
                if (mp.find(complement2) != mp.end())
                    cnt += mp[complement2];
            mp[it]++;
        }
        return cnt;
    }
};