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
    string result;
    void dfs(TreeNode* root, string current){
        if(!root) return;

        current = char(root->val + char('a')) + current;

        if(root->left == NULL and root->right == NULL){
            if(result == "" || result > current){
                result = current;
            }
            return;
        }
        dfs(root->left, current);
        dfs(root->right, current);

    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return result;
    }
};