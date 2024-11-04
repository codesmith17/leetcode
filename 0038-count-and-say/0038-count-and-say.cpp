class Solution {
public:
    string countAndSay(int n) {
        string current = "1";
        for (int i = 2; i <= n; i++) {
            int sz = current.size();
            string newCurrent;
            for (int j = 0; j < sz;) {
                char currentChar = current[j];
                int currentCount = 0;
                while (j < sz and currentChar == current[j]) {
                    currentCount++;
                    j++;
                }

                string counter = to_string(currentCount);
                for (auto& it : counter)
                    newCurrent.push_back(it);
                newCurrent.push_back(currentChar);
            }
            current = newCurrent;
        }
        return current;
    }
};