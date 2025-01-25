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
    TreeNode* helper(vector<int> &preorder, vector<int> &inorder, int &preorderIndex, 
    int inorderStart, int inorderEnd, unordered_map<int, int> &inordermap){
        
        if(inorderStart > inorderEnd) return nullptr;

        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);

        int inorderIndex = inordermap[rootValue];

        root->left = helper(preorder, inorder, preorderIndex, inorderStart, inorderIndex-1, inordermap);
        root->right = helper(preorder, inorder, preorderIndex, inorderIndex + 1, inorderEnd, inordermap);  

        return root;
    
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inordermap;

        for(int i = 0; i < inorder.size(); i++)
        {
            inordermap[inorder[i]] = i;
        }
        int preorderIndex = 0;
        return helper(preorder, inorder, preorderIndex , 0, inorder.size() - 1, inordermap);
    }
};