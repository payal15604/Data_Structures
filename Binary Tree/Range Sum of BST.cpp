class Solution {
public:
    int traverse(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }

        int sum = 0;
        if (root->val >= low && root->val <= high) {
            sum += root->val;
        }

        // Traverse left and right subtrees
        sum += traverse(root->left, low, high);
        sum += traverse(root->right, low, high);

        return sum;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        return traverse(root, low, high);
    }
};
