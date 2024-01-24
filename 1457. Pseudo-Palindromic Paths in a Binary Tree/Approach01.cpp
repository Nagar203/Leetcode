#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
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
    
    void solve(TreeNode* root, int path, int& result) {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr) {
            path ^= 1 << root->val;
            if ((path & (path - 1)) == 0)
                ++result;
            return;
        }

        solve(root->left, path ^ 1 << root->val, result);
        solve(root->right, path ^ 1 << root->val, result);
    }
    
    int pseudoPalindromicPaths(TreeNode* root) {
        int result = 0;
        solve(root, 0, result);
        return result;
    }
  
};