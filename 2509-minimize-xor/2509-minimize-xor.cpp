class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int requiredSetBits = __builtin_popcount(num2);
        vector<bool> number(32, false);

        for (int i = 31; i >= 0; i--) {
            if (requiredSetBits > 0 and (num1 & (1 << i)) != 0) {
                number[i] = true;
                requiredSetBits--;
            }
        }

        if (requiredSetBits > 0) {
            for (int i = 0; i < 32; i++) {
                if (!number[i]) {
                    number[i] = true;
                    requiredSetBits--;
                    if (requiredSetBits == 0)
                        break;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < 32; i++)
            res += pow(2, i) * number[i];

        return res;
    }
};
