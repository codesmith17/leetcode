class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = s.length();
        long long p = 1;
        long long curr = 0;
        int resultIndex = 0;
        for (int i = 0; i < k - 1; i++)
            p = (p * power) % modulo;

        for (int i = n - 1; i >= n - k; i--) {
            curr = (curr * power + (s[i] - 'a' + 1)) % modulo;
        }

        if (curr == hashValue) {
            resultIndex = n - k;
        }

        for (int i = n - k - 1; i >= 0; i--) {
            curr =
                (curr - ((s[i + k] - 'a' + 1) * p) % modulo + modulo) % modulo;

            curr = (curr * power + (s[i] - 'a' + 1)) % modulo;

            if (curr == hashValue) {
                resultIndex = i;
            }
        }

        return s.substr(resultIndex, k);
    }
};