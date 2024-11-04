class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int n = word.size();
        for (int i = 0; i < n;) {
            char current = word[i];
            int cnt = 0;
            int j;
            for (j = i; j < n and cnt < 9; j++) {
                if (current == word[j]) {
                    cnt++;
                } else {
                    break;
                }
            }
            comp.push_back(to_string(cnt)[0]);
            comp.push_back(current);
            i = j;
        }
        return comp;
    }
};
