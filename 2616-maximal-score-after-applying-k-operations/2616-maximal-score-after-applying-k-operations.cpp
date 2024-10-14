class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long res = 0;
        priority_queue<int> pq(nums.begin(), nums.end());
        while (pq.size() and k--) {
            int top = pq.top();
            res += top;
            pq.pop();
            pq.push(ceil(top / 3.0));
        }
        return res;
    }
};