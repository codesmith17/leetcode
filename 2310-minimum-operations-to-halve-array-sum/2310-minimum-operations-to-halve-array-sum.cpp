class Solution {
public:
    int halveArray(vector<int>& nums) {
        long long initialSum = accumulate(nums.begin(), nums.end(), 0LL);
        priority_queue<double> pq;
        double currentSum = initialSum;
        for (auto it : nums)
            pq.push(it);
        int steps = 0;
        while (pq.size() and currentSum > initialSum / 2.0) {
            double top = pq.top();
            pq.pop();
            top /= 2.0;
            currentSum -= top;
            pq.push(top);
            steps++;
        }
        return steps;
    }
};