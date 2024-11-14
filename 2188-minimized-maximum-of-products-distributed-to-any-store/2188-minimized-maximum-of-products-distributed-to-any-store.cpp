class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int maxe = *max_element(quantities.begin(), quantities.end());
        int s = 1, e = maxe;
        int res = e;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            long long currentSum = 0;

            for (auto& it : quantities) {
                currentSum += (it + mid - 1) / mid; // ceil((double)it / mid)
            }

            if (currentSum <= n) {
                res = mid;
                e = mid - 1;
            } else
                s = mid + 1;
        }

        return res;
    }
};
