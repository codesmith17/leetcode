class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        int maxOnes = -1e9;
        for (int i = 0; i < 32; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++)
                cnt += ((candidates[j] & (1 << i)) > 0);
            maxOnes = max(maxOnes, cnt);
        }
        return maxOnes;
    }
};