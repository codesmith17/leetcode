class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long res = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int currentValue = nums[i];

            int s = i + 1, e = n - 1;
            while (s <= e) {
                int mid = s + (e - s) / 2;
                if (currentValue + nums[mid] >= lower)
                    e = mid - 1;
                else
                    s = mid + 1;
            }
            int leftBound = s;
            e = n - 1;
            while (s <= e) {
                int mid = s + (e - s) / 2;
                if (currentValue + nums[mid] <= upper)
                    s = mid + 1;
                else
                    e = mid - 1;
            }
            int rightBound = e;

            if (leftBound <= rightBound)
                res += (rightBound - leftBound + 1);
        }

        return res;
    }
};
