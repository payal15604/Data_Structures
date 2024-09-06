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
    string dfs(TreeNode* node, vector<TreeNode*> &ans, unordered_map<string,vector<TreeNode*>> &hash){
        //preorder traversal
        if(node == nullptr){
            return "null";
        }

        string s = to_string(node->val) +","+dfs(node->left, ans, hash) + ","+dfs(node->right, ans, hash);
        if(hash[s].size() == 1){
            ans.emplace_back(node);
        }
        hash[s].emplace_back(node);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> hash;
        vector<TreeNode*> ans;
        dfs(root, ans, hash);

        return ans;

    }
};