class Solution {
public:
    std::set<int>::iterator lb(const std::set<int>& s, int value) {
        auto begin = s.begin();
        auto end = s.end();
        auto result = end; // Default to end if no lower bound is found.

        while (begin != end) {
            auto mid = begin;
            std::advance(mid, std::distance(begin, end) /
                                  2); // Efficiently find the middle.

            if (*mid < value) {
                begin = std::next(mid);
            } else {
                end = mid; // Include mid in the search range for lower_bound.
            }
        }
        return result;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff,
                                       int valueDiff) {
        set<int> st;
        st.insert(nums[0]);
        int n = nums.size();
        //>=valDIff+nums[j] or <=valDiff+nums[j]
        for (int i = 1; i < n; i++) {
            if (i > indexDiff)
                st.erase(nums[i - indexDiff - 1]);
            auto position = st.lower_bound(nums[i] - valueDiff);
            if (position != st.end() and *position - nums[i] <= valueDiff)
                return true;
            st.insert(nums[i]);
        }
        return false;
    }
};