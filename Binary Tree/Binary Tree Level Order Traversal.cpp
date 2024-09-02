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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans; 

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int qsize = q.size();
            vector<int> level;
            for(int i = 0; i < qsize; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr != nullptr){
                    level.emplace_back(curr->val);
                    if(curr->left != nullptr){q.push(curr->left);}
                    if(curr->right != nullptr){q.push(curr->right);}
                }
            }
            if(level.size() != 0){
            ans.emplace_back(level);
            }
        }

        return ans;
    }
};