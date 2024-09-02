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
    void dfs(TreeNode* node, int &mini, TreeNode* &prev){
        if (node == nullptr){
            return ;
        }

        dfs(node->left, mini, prev);
        if(prev != nullptr){
            mini = min(mini, abs(node->val - prev->val));
        }

        prev = node;
        dfs(node->right, mini, prev);
    }
    int minDiffInBST(TreeNode* root) {
        int mini = INT_MAX;
        TreeNode* prev = nullptr;
        dfs(root, mini, prev);

        return mini;
    }
};