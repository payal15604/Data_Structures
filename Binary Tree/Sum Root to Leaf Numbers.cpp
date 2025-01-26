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
    int helper(TreeNode* node, int currnum, int &totalsum)
    {
        if (node == nullptr) return 0;

        currnum = currnum*10 + node->val;

        if(node->left == nullptr && node->right == nullptr) totalsum += currnum;

        int leftsum = helper(node->left, currnum, totalsum);
        int rightsum = helper(node->right, currnum, totalsum);

        return leftsum + rightsum;
    }
    int sumNumbers(TreeNode* root) {
        int currnum = 0;
        int totalsum = 0;
        int calc = helper(root, currnum, totalsum);

        return totalsum;


    }
};