class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        long long waitTime = customers[0][1];
        int startTime = customers[0][1] + customers[0][0];
        for (int i = 1; i < n; i++) {
            if (startTime > customers[i][0]) {
                waitTime += startTime - customers[i][0];
            } else {
                startTime = customers[i][0];
            }
            waitTime += customers[i][1];
            startTime += customers[i][1];
        }
        return waitTime * 1.0 / n;
    }
};