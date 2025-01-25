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
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
};

//iterative approach

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
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        int maxDepth = 1;

        if(root == nullptr) return 0;

        while(!st.empty())
        {
            auto [curr, depth] = st.top();
            st.pop();

            if(curr->left != nullptr)
            {
                st.push({curr->left, depth + 1});
            }

            if(curr->right != nullptr)
            {
                st.push({curr->right, depth +1});
            }

            maxDepth = max(maxDepth, depth);
        }
        
        return maxDepth;
    }
};