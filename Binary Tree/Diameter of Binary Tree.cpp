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
    int maxDepth(TreeNode* node)
    {
       if(node == NULL){
        return 0;
       }

       return 1 + max(maxDepth(node->right), maxDepth(node->left));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }

        int rootDiameter = maxDepth(root->left) + maxDepth(root->right);

        int leftdia = diameterOfBinaryTree(root->left);
        int rightdia = diameterOfBinaryTree(root->right);

        return max(rootDiameter, max(leftdia, rightdia)); 
    }
};