class Solution {
public:
    int maximumSwap(int num) {
        string number = to_string(num);
        short maxDigit = -1;
        short n = number.size(), maxIndex = -1, s = -1, e = -1;
        for (short i = n - 1; i >= 0; i--) {
            if (number[i] - '0' > maxDigit)
                maxDigit = number[i] - '0', maxIndex = i;
            else if (number[i] - '0' < maxDigit) {
                s = i;
                e = maxIndex;
            }
        }
        if (s == -1)
            return num;
        swap(number[s], number[e]);
        return stoi(number);
    }
};