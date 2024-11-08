class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> prefixXor(n);
        prefixXor[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefixXor[i] = prefixXor[i - 1] ^ nums[i];

        int maxNum = (1 << maximumBit) - 1;
        for (int i = n - 1; i >= 0; i--) {
            prefixXor[i] = (prefixXor[i] ^ maxNum);
        }
        reverse(prefixXor.begin(), prefixXor.end());

        return prefixXor;
    }
};
