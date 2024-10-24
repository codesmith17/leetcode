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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        queue<TreeNode*> q1, q2;
        if (root1)
            q1.push(root1);
        if (root2)
            q2.push(root2);
        if (q1.size() != q2.size())
            return false;

        while (!q1.empty()) {
            if (q1.front()->val != q2.front()->val)
                return false;
            addChildren(q1);
            addChildren(q2);
        }

        return q1.empty() == q2.empty();
    }

private:
    void addChildren(queue<TreeNode*>& q) {
        if (q.empty())
            return;

        TreeNode* node = q.front();
        q.pop();
        if (node->left && node->right) {
            if (node->left->val > node->right->val)
                swap(node->left, node->right);
            q.push(node->left);
            q.push(node->right);
        } else if (node->left || node->right) {
            TreeNode* child = node->left ? node->left : node->right;
            child->val +=
                node->val;
            q.push(child);
        }
    }
};