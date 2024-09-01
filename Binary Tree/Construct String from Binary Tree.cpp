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
    void preorder(TreeNode* root, vector<string> &s){
        if(root == nullptr){
            return ;
        }

        s.emplace_back("(");
        s.emplace_back(to_string(root->val));
        if(root->left == nullptr && root->right != nullptr){
            s.emplace_back("()");
        }
        preorder(root->left, s);
        preorder(root->right, s);
        s.emplace_back(")");

    }
    string tree2str(TreeNode* root) {
        vector<string> s;
        preorder(root, s);

        string ans;

        for(int i = 0; i < s.size(); i++){
            ans.append(s[i]);
        }

        return ans.substr(1, ans.size()-2);
    }
};