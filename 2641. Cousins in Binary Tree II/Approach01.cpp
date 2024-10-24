class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size(), levelSum = 0;
            vector<TreeNode*> nodesAtCurrentLevel;

            // Process each node at the current level
            while (levelSize--) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();
                nodesAtCurrentLevel.push_back(currentNode);

                if (currentNode->left) {
                    nodeQueue.push(currentNode->left);
                    levelSum += currentNode->left->val;
                }
                if (currentNode->right) {
                    nodeQueue.push(currentNode->right);
                    levelSum += currentNode->right->val;
                }
            }

            // Replace node values based on cousin sum
            for (auto currentNode : nodesAtCurrentLevel) {
                int cousinSum = levelSum;
                if (currentNode->left)
                    cousinSum -= currentNode->left->val;
                if (currentNode->right)
                    cousinSum -= currentNode->right->val;
                if (currentNode->left)
                    currentNode->left->val = cousinSum;
                if (currentNode->right)
                    currentNode->right->val = cousinSum;
            }
        }
        return root;
    }
};
