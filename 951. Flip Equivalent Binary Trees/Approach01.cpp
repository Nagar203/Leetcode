class Solution {
public:
    bool flipEquiv(TreeNode* tree1, TreeNode* tree2) {
        if (tree1 == nullptr)
            return tree2 == nullptr;
        if (tree2 == nullptr)
            return tree1 == nullptr;
        if (tree1->val != tree2->val)
            return false;
        
        // Check for flip equivalence in both flipped and non-flipped scenarios
        return (flipEquiv(tree1->left, tree2->left) && 
                flipEquiv(tree1->right, tree2->right)) || 
               (flipEquiv(tree1->left, tree2->right) && 
                flipEquiv(tree1->right, tree2->left));
    }
};