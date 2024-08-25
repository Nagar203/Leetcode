#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traversePostorder(root, result);
        return result;
    }

private:
    void traversePostorder(TreeNode* node, vector<int>& result) {
        if (node == nullptr)
            return;

        traversePostorder(node->left, result);
        traversePostorder(node->right, result);
        result.push_back(node->val);
    }
};