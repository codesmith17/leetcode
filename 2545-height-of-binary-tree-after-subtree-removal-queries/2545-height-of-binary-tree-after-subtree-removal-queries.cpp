
class Solution {
public:
    int maxDepth(TreeNode* node, unordered_map<int, int>& height, unordered_map<int, int>& level, int currentLevel) {
        if (node == nullptr)
            return 0;
        
        level[node->val] = currentLevel;
        int lDepth = maxDepth(node->left, height, level, currentLevel + 1);
        int rDepth = maxDepth(node->right, height, level, currentLevel + 1);
        
        height[node->val] = max(lDepth, rDepth) + 1;
        return height[node->val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int, int> height, level;
        maxDepth(root, height, level, 0);
        unordered_map<int, vector<int>> levelHeights;
        queue<TreeNode*> q;
        q.push(root);
        int currentLevel = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<int> heights;
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                heights.push_back(height[node->val]);
                
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            sort(heights.rbegin(), heights.rend());
            if (heights.size() > 2) heights.resize(2);
            levelHeights[currentLevel] = heights;

            currentLevel++;
        }

        vector<int> res;
        for (int currentNode : queries) {
            int currentLevel = level[currentNode];
            int currentHeight = height[currentNode];
            vector<int> heights = levelHeights[currentLevel];
            
            if (heights.size() == 1 or (heights.size() == 2 and heights[0] == currentHeight)) {
                res.push_back(currentLevel + (heights.size() == 2 ? heights[1] : 0) - 1);
            } else {
                res.push_back(currentLevel + heights[0] - 1);
            }
        }

        return res;
    }
};
