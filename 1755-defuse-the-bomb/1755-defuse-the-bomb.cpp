class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);

        if (k == 0)
            return res;

        int sum = 0, s, e;
        if (k > 0) {
            for (int i = 1; i <= k; i++) {
                sum += code[i % n];
            }
            s = 1;
            e = k;
        } else {
            for (int i = n + k; i < n; i++)
                sum += code[i];

            s = n + k;
            e = n - 1;
        }

        res[0] = sum;

        for (int i = 1; i < n; i++) {
            sum -= code[s++ % n];
            sum += code[++e % n];
            res[i] = sum;
        }

        return res;
    }
};
