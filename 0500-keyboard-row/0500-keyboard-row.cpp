class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int n = words.size();
        string row1 = "qwertyuiop", row2 = "asdfghjkl", row3 = "zxcvbnm";
        vector<string> res;
        for (int i = 0; i < n; i++) {
            string currentWord = words[i];
            transform(currentWord.begin(), currentWord.end(),
                      currentWord.begin(), ::tolower);
            int sz = currentWord.size();
            short currentRow = -1;
            bool flag = true;
            for (auto& it : currentWord) {
                if (currentRow == -1) {
                    if (row1.find(it) != string::npos) {
                        currentRow = 1;
                    } else if (row2.find(it) != string::npos) {
                        currentRow = 2;

                    } else if (row3.find(it) != string::npos) {
                        currentRow = 3;
                    }
                } else {
                    int prevRow = currentRow;
                    if (row1.find(it) != string::npos) {
                        currentRow = 1;
                    } else if (row2.find(it) != string::npos) {
                        currentRow = 2;

                    } else if (row3.find(it) != string::npos) {
                        currentRow = 3;
                    }
                    if (prevRow != currentRow) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag)
                res.push_back(words[i]);
        }
        return res;
    }
};