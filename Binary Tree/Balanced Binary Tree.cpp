class Solution {
public:
    int maxDepth(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + max(maxDepth(node->left), maxDepth(node->right));
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true; // An empty tree is balanced.
        }

        // Check the balance of the left and right subtrees.
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // Check if the current node is balanced and if its left and right subtrees are balanced.
        if (abs(leftDepth - rightDepth) > 1) {
            return false; // Not balanced if the height difference is more than 1.
        }

        // Recursively check for each subtree.
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
