class Solution {
public:
    TreeNode* newroot = new TreeNode();  // Member variable declaration

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return nullptr;
        }

        if (root1 != nullptr && root2 != nullptr) {
            TreeNode* newroot = new TreeNode(root1->val + root2->val);  // Create new node
            newroot->left = mergeTrees(root1->left, root2->left);       // Recursively merge left subtrees
            newroot->right = mergeTrees(root1->right, root2->right);    // Recursively merge right subtrees
            return newroot;  // Return merged tree root
        }

        if (root1 == nullptr) {
            TreeNode* newroot = new TreeNode(root2->val);               // Create new node from root2
            newroot->left = mergeTrees(nullptr, root2->left);           // Recursively merge left subtree of root2
            newroot->right = mergeTrees(nullptr, root2->right);         // Recursively merge right subtree of root2
            return newroot;  // Return merged tree root
        }

        if (root2 == nullptr) {
            TreeNode* newroot = new TreeNode(root1->val);               // Create new node from root1
            newroot->left = mergeTrees(root1->left, nullptr);           // Recursively merge left subtree of root1
            newroot->right = mergeTrees(root1->right, nullptr);         // Recursively merge right subtree of root1
            return newroot;  // Return merged tree root
        }

        return nullptr;  // This line is technically unreachable due to previous checks
    }
};
