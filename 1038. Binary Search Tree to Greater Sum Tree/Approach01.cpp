#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int prefix_sum = 0;

        function<void(TreeNode*)> reversed_inorder_traversal = [&](TreeNode* node) {
                if (node == nullptr)
                    return;

                reversed_inorder_traversal(node->right);

                node->val += prefix_sum;
                prefix_sum = node->val;

                reversed_inorder_traversal(node->left);
            };

        reversed_inorder_traversal(root);
        return root;
    }
};