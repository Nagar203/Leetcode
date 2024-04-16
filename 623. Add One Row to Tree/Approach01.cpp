#include <bits/stdc++.h>

using namespace std;
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
public:
    TreeNode* solve(TreeNode* root, int val, int depth, int current) {
        if (root == nullptr) {
            return nullptr;
        }
        if (current == depth - 1) {
            TreeNode* temp_left = root->left;
            TreeNode* temp_right = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            root->left->left = temp_left;
            root->right->right = temp_right;

            return root;
        }
        root->left = solve(root->left, val, depth, current + 1);
        root->right = solve(root->right, val, depth, current + 1);
        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* new_node = new TreeNode(val);
            new_node->left = root;
            return new_node;
        }

        int current = 1;
        return solve(root, val, depth, current);
    }
};