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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr){return ans;}
        queue<TreeNode*> q;
        q.push(root);

      

        while(!q.empty()){
            int qLen = q.size();
            vector<int> level;
            for(int i = 0; i < qLen; i++){
                TreeNode* curr = q.front();
                q.pop();
                level.emplace_back(curr->val);

                if(curr->left != nullptr){
                    q.push(curr->left);
                }

                if(curr->right != nullptr){
                    q.push(curr->right);
                }
            }

            ans.emplace_back(level);


        }

        for(int i = 0; i < ans.size(); i++)
        {
            if (i%2!=0){
                reverse(ans[i].begin(), ans[i].end());
            }
        }


        return ans;
    }


};