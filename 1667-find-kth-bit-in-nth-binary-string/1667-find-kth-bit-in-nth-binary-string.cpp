class Solution {
public:
    string recursion(int n, int k) {
        if (n == 1)
            return "0";
        string s = recursion(n - 1, k);
        if (s.size() > k)
            return s;
        string inverted = s;
        for (auto& it : inverted) {
            it = (it == '0') ? '1' : '0';
        }
        reverse(inverted.begin(), inverted.end());
        return s + "1" + inverted;
    }

    char findKthBit(int n, int k) {
        string s = recursion(n, k);
        return s[k - 1];
    }
};