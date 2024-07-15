class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<TreeNode*, TreeNode*> childToParentMap;
        unordered_map<int, TreeNode*> valueToNodeMap;

        for (const vector<int>& description : descriptions) {
            const int parentValue = description[0];
            const int childValue = description[1];
            const bool isLeftChild = description[2];

            TreeNode* parentNode = valueToNodeMap.count(parentValue) ? valueToNodeMap[parentValue] : (valueToNodeMap[parentValue] = new TreeNode(parentValue));
            TreeNode* childNode = valueToNodeMap.count(childValue) ? valueToNodeMap[childValue] : (valueToNodeMap[childValue] = new TreeNode(childValue));

            childToParentMap[childNode] = parentNode;

            if (isLeftChild){
                parentNode->left = childNode;
            }
            else{
                parentNode->right = childNode;
            }
        }

        // Pick a random node and traverse upward to find the root.
        TreeNode* root = childToParentMap.begin()->second;
        while (childToParentMap.count(root)){
            root = childToParentMap[root];
        }
        return root;
    }
};
