#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> result;

        calculateHeights(root, 0, 0);

        for (const int query : queries){
            result.push_back(nodeToMaxHeight[query]);
        }

        return result;
    }

private:
    // nodeToMaxHeight[val] stores the maximum height of the tree without the
    // node with `val`
    unordered_map<int, int> nodeToMaxHeight;
    // nodeToHeight[val] stores the height of the node with `val`
    unordered_map<int, int> nodeToHeight;

    // Helper function to calculate the height of a node
    int getHeight(TreeNode* root) {
        if (root == nullptr)
            return 0;
        if (const auto it = nodeToHeight.find(root->val);
            it != nodeToHeight.cend())
            return it->second;
        return nodeToHeight[root->val] = (1 + max(getHeight(root->left), getHeight(root->right)));
    }

    // maxHeight: the maximum height excluding the current node `root`
    void calculateHeights(TreeNode* root, int currentDepth, int maxHeight) {
        if (root == nullptr)
            return;
        nodeToMaxHeight[root->val] = maxHeight;
        calculateHeights(root->left, currentDepth + 1, max(maxHeight, currentDepth + getHeight(root->right)));
        calculateHeights(root->right, currentDepth + 1, max(maxHeight, currentDepth + getHeight(root->left)));
    }
};
