class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        if (n < 2)
            return 0;
        vector<int> cache;
        for (auto& it : bank)
            if (count(it.begin(), it.end(), '1') > 0)
                cache.push_back(count(it.begin(), it.end(), '1'));
        int cnt = 0;
        n = cache.size();
        if (cache.size() < 2)
            return 0;
        for (int i = 0; i < cache.size() - 1; i++)
            cnt += (cache[i] * cache[i + 1]);

        return cnt;
    }
};