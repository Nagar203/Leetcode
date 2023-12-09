#include <iostream>
#include <vector>

using namespace std;


//  Definition for a binary tree node.
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) return {};

        vector<int> result;

        vector<int> leftResult = inorderTraversal(root->left);
        result.insert(result.end(), leftResult.begin(), leftResult.end());
        result.push_back(root->val);
        vector<int> rightResult = inorderTraversal(root->right);

        result.insert(result.end(), rightResult.begin(), rightResult.end());

        return result;
    }
};