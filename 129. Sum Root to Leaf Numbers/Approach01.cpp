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
    int solve(TreeNode* root,int current){
        if(!root){
            return 0;
        }
        current = (current*10) + root->val;
        if(root->left == NULL && root->right == NULL){
            return current; 
        }

        int left = solve(root->left, current);
        int right = solve(root->right, current);

        return (left + right);
    }
    int sumNumbers(TreeNode* root) {
        return solve(root, 0); 
    }
};