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
    int sum = 0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return false;
        }
        if(root->left == nullptr && root->right == nullptr){
            return root->val == targetSum;
        }
        bool lefttree = hasPathSum(root->left, targetSum - root->val);
        bool righttree = hasPathSum(root->right, targetSum - root->val);

        return righttree || lefttree;
    }
};