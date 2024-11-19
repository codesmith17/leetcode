class Solution {
public:
    int MOD = 1e9 + 7;

    long long factorial(int n) {
        long long res = 1;
        for (int i = 2; i <= n; i++) {
            res = (res * i) % MOD;
        }
        return res;
    }

    long long modInverse(long long a, long long m) {
        long long res = 1, power = m - 2;
        while (power > 0) {
            if (power & 1) {
                res = (res * a) % m;
            }
            a = (a * a) % m;
            power = power >> 1;
        }
        return res;
    }

    int countAnagrams(string s) {
        int n = s.size();
        long long res = 1;
        int sz = 0;
        vector<int> mp(26, 0);

        for (int i = 0; i <= n; i++) {
            if (i == n or s[i] == ' ') {
                if (sz > 0) {
                    long long res1 = 1;
                    for (int j = 0; j < 26; j++) {
                        if (mp[j] > 0) {
                            res1 = (res1 * factorial(mp[j])) % MOD;
                            mp[j] = 0;
                        }
                    }
                    res = (res * factorial(sz)) % MOD;
                    res = (res * modInverse(res1, MOD)) % MOD;
                }
                sz = 0;
            } else {
                sz++;
                mp[s[i] - 'a']++;
            }
        }

        return (int)res;
    }
};
