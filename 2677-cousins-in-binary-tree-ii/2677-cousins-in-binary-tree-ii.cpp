/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> sumHeight;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {

            int sum = 0;
            int size = q.size();
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                sum+=node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            sumHeight.push_back(sum);
        }
        q.push(root);
        int height = 1;
        root->val = 0;
        while (q.size()) {

            int size = q.size();
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left and node->right) {
                    node->right->val = node->left->val =
                        sumHeight[height] - node->left->val - node->right->val;
                    q.push(node->left);
                    q.push(node->right);
                } else if (node->left) {
                    node->left->val = sumHeight[height] - node->left->val;
                    q.push(node->left);
                } else if (node->right) {
                    node->right->val = sumHeight[height] - node->right->val;
                    q.push(node->right);
                }
            }
            height++;
        }
        return root;
    }
};