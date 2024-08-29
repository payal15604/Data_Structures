/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> helper(TreeNode* node, vector<int>& path) {
        if (node == NULL)
            return path;

        path = helper(node->left, path);
        path.push_back(node->val);
        path = helper(node->right, path);
        return path;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> path;
        path = helper(root, path);
        return path;
    }
};