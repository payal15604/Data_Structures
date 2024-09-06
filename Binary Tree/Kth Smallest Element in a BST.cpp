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
    int inorder(TreeNode* node, int &k){
        if(node == nullptr){return -1;}
      
        int left = inorder(node->left, k);
        if(k == 0){return left;}
        k--;
        if (k == 0) return node->val;
        return inorder(node->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
};