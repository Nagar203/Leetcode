#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> remainingTrees;
        // Create a set from to_delete vector for quick lookup
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        // Start the DFS removal process
        removeNodes(root, toDeleteSet, true, remainingTrees);
        return remainingTrees;
    }

private:
    // Helper function to perform DFS and remove nodes
    TreeNode* removeNodes(TreeNode*& node, const unordered_set<int>& toDeleteSet, bool isRoot, vector<TreeNode*>& remainingTrees) {
        if (node == nullptr){
            return nullptr;
        }

        // Check if the current node needs to be deleted
        const bool isDeleted = toDeleteSet.count(node->val) > 0;

        // If the current node is a root and not deleted, add it to the result
        if (isRoot && !isDeleted){
            remainingTrees.push_back(node);
        }

        // Recursively process the left and right subtrees
        node->left =  removeNodes(node->left, toDeleteSet, isDeleted, remainingTrees);
        node->right = removeNodes(node->right, toDeleteSet, isDeleted, remainingTrees);

        // Return nullptr if the node is deleted, otherwise return the node
        // itself
        return isDeleted ? nullptr : node;
    }
};
