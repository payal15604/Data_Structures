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
    int longest = 0;
    int helper(TreeNode* node)
    {
        if(node == nullptr) return 0;

        int leftsum = helper(node->left);
        int rightsum = helper(node->right);

        int leftext = (node->left != nullptr && node->left->val == node->val) ? leftsum + 1:0;
        int rightext = (node->right != nullptr && node->right->val == node->val) ? rightsum + 1:0;

        longest = max(longest, leftext+rightext);

        return max(leftext, rightext);
    }
    int longestUnivaluePath(TreeNode* root) {
        helper(root);
        return longest;
    }
};