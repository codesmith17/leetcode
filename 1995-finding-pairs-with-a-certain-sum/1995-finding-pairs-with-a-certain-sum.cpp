class FindSumPairs {
public:
    vector<int> nums1, nums2;
    unordered_map<int, int> mp;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (auto& it : nums2)
            mp[it]++;
    }

    void add(int index, int val) {
        mp[nums2[index]]--;
        if (mp[nums2[index]] == 0)
            mp.erase(nums2[index]);
        nums2[index] += val;
        mp[nums2[index]]++;
    }

    int count(int tot) {
        int res = 0;
        for (auto& it : nums1) {
            int complement = tot - it;
            if (mp.find(complement) != mp.end())
                res += mp[complement];
        }
        return res;
    }
};
