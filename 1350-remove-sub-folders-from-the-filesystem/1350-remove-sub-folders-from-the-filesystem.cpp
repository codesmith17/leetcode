class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;
        for (auto& it : folder)
            if (res.empty() or
                it.substr(0, res.back().size() + 1) != res.back() + "/")
                res.push_back(it);

        return res;
    }
};
