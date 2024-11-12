class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        sort(items.begin(), items.end());

        vector<int> maxElements;
        int maxe = 0;
        for (auto& it : items) {
            maxe = max(maxe, it[1]);
            maxElements.push_back(maxe);
        }

        vector<int> res;
        for (auto& it : queries) {
            int s = 0, e = items.size() - 1;
            int currentResult = -1;

            while (s <= e) {
                int mid = s + (e - s) / 2;
                if (items[mid][0] <= it) {
                    currentResult = maxElements[mid];
                    s = mid + 1;
                } else
                    e = mid - 1;
            }

            res.push_back(currentResult == -1 ? 0 : currentResult);
        }
        return res;
    }
};
