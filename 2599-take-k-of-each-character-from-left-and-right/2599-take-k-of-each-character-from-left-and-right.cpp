class Solution {
public:
    int takeCharacters(string s, int k) {
        // max substring of a-k,b-k,c-k
        vector<int> mp(3, 0);
        for (char& ch : s)
            mp[ch - 'a']++;
        for (int& it : mp) {
            if (it < k) {
                return -1;
            }
        }
        int notDeletedSize = -1e9;
        int i = 0, j = 0, n = s.size();
        while (j < n) {
            mp[s[j] - 'a']--;
            while (i <= j and (mp[0] < k or mp[1] < k or mp[2] < k)) {
                mp[s[i] - 'a']++;
                i++;
            }
            notDeletedSize = max(notDeletedSize, j - i + 1);
            j++;
        }
        return n - notDeletedSize;
    }
};