#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSubPath(ListNode* linkedListHead, TreeNode* treeRoot) {
        if (treeRoot == nullptr)
            return false;
        return hasPathStartingFromNode(linkedListHead, treeRoot) ||
               isSubPath(linkedListHead, treeRoot->left) ||
               isSubPath(linkedListHead, treeRoot->right);
    }

private:
    bool hasPathStartingFromNode(ListNode* currentListNode, TreeNode* currentTreeNode) {
        if (currentListNode == nullptr)
            return true;
        if (currentTreeNode == nullptr)
            return false;
        return currentListNode->val == currentTreeNode->val && (hasPathStartingFromNode(currentListNode->next, currentTreeNode->left) || hasPathStartingFromNode(currentListNode->next, currentTreeNode->right));
    }
};