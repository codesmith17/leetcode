class Solution {
public:
    vector<int> finalPrices(vector<int>& nums) {
        vector<int> nse(nums.size(), 0);
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            nse[i] = st.empty() ? 0 : nums[st.top()];
            st.push(i);
        }
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = nums[i] - nse[i];
        }
        return ans;
    }
};