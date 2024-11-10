class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bits(32, 0);
        int s = 0, e = 0, res = 1e9;
        int currentOR = 0;
        while (e < n) {
            currentOR |= nums[e];
            for (int i = 0; i < 32; i++)
                if (nums[e] & (1 << i))
                    bits[i]++;
            while (s <= e and currentOR >= k) {
                res = min(res, e - s + 1);
                int leftValue = nums[s];
                for (int i = 0; i < 32; i++) {
                    bits[i] -= ((nums[s] & (1 << i)) > 0);
                }
                int updatedOR = 0;
                for (int i = 0; i < 32; i++)
                    if (bits[i])
                        updatedOR += pow(2, i);

                currentOR = updatedOR;
                s++;
            }
            e++;
        }
        return 1e9 == res ? -1 : res;
    }
};