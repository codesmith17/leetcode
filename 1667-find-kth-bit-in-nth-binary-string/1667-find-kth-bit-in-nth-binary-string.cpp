class Solution {
public:
    string recursion(int n) {
        if (n == 1) {
            return "0";
        }
        string s = recursion(n - 1);
        string inverted = s;
        for (auto &it : inverted) {
            it = (it == '0') ? '1' : '0';
        }
        reverse(inverted.begin(), inverted.end());
        return s + "1" + inverted;
    }

    char findKthBit(int n, int k) {
        string s = recursion(n);
        return s[k - 1];
    }
};