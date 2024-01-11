#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
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
    int result;
    
    int get_root(TreeNode* root, int max_val, int min_val){
        if(root==NULL){
            return abs(max_val - min_val);
        }
        
        max_val = max(max_val, root->val);
        min_val = min(min_val, root->val);

        int left_result = get_root(root->left, max_val, min_val);
        int right_result = get_root(root->right, max_val, min_val);
        
        return max(left_result, right_result);
    }

    int maxAncestorDiff(TreeNode* root) {
        return get_root(root, root->val, root->val);
    }
};