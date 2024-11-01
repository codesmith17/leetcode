class Solution {
public:
    string makeFancyString(string s) {
        int cnt = 1, n = s.size();
        string res;
        res.push_back(s[0]);
        for (int i = 1; i < n; i++) {
            s[i] == s[i - 1] ? cnt++ : cnt = 1;
            if (cnt < 3)
                res.push_back(s[i]);
        }
        return res;
    }
};