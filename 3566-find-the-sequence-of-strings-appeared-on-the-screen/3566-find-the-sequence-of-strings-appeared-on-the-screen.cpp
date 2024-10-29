class Solution {
public:
    vector<string> stringSequence(string target) {
        string currentString = "a";
        vector<string> res;
        while (currentString <= target) {
            res.push_back(currentString);
            if (currentString.back() != target[currentString.size() - 1])
                currentString.back()++;
            else
                currentString.push_back('a');
        }
        return res;
    }
};