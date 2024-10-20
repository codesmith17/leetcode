class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (auto it : nums)
            mp[it]++;
        vector<int>res;
        for (auto it : nums)
            if (mp.find(it) != mp.end())
                if (mp[it] == 1)
                    if (mp.find(it - 1) == mp.end())
                        if (mp.find(it + 1) == mp.end())
                            res.push_back(it);
        return res;
    }
};