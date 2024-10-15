class Solution {
public:
    long long minimumSteps(string s) {

        long long cnt = 0;
        int onesTillNow = 0;

        for (auto it : s) {
            if (it == '1')
                onesTillNow++;
            else
                cnt += onesTillNow;
        }

        return cnt;
    }
};