class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string currentPath;
        string pathToStart;
        string pathToDest;

        // Find the lowest common ancestor and start DFS from there.
        dfs(findLCA(root, startValue, destValue), startValue, destValue, currentPath, pathToStart, pathToDest);

        // Construct the path by going up to the common ancestor and then down to the destination.
        return string(pathToStart.length(), 'U') + pathToDest;
    }

private:
    // Function to find the lowest common ancestor (LCA) of two nodes.
    TreeNode* findLCA(TreeNode* root, int p, int q) {
        if (root == nullptr || root->val == p || root->val == q) {
            return root;
        }

        TreeNode* leftLCA = findLCA(root->left, p, q);
        TreeNode* rightLCA = findLCA(root->right, p, q);

        if (leftLCA != nullptr && rightLCA != nullptr) {
            return root;
        }

        return leftLCA == nullptr ? rightLCA : leftLCA;
    }

    // DFS to find paths from the LCA to the start and destination nodes.
    void dfs(TreeNode* root, int startValue, int destValue, string& currentPath, string& pathToStart, string& pathToDest) {
        if (root == nullptr) {
            return;
        }

        if (root->val == startValue) {
            pathToStart = currentPath;
        }

        if (root->val == destValue) {
            pathToDest = currentPath;
        }

        // Traverse left subtree
        currentPath.push_back('L');
        dfs(root->left, startValue, destValue, currentPath, pathToStart, pathToDest);
        currentPath.pop_back();

        // Traverse right subtree
        currentPath.push_back('R');
        dfs(root->right, startValue, destValue, currentPath, pathToStart, pathToDest);
        currentPath.pop_back();
    }
};
