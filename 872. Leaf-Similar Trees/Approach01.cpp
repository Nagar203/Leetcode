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
    void in_order(TreeNode* root, string& s){
        if(root==NULL) return;

        if(root->left == NULL and root->right == NULL){
            s += to_string(root->val) + "_";
        }

        in_order(root->left, s);
        in_order(root->right, s);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1 = "";
        string s2 = "";

        in_order(root1, s1);
        in_order(root2, s2);

        return s1==s2;

    }
};