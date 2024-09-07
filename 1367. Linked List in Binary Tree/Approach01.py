from typing import *

class Solution:
    def isSubPath(self, linkedListHead: Optional[ListNode], treeRoot: Optional[TreeNode]) -> bool:
        if treeRoot is None:
            return False
        return self.hasPathStartingFromNode(linkedListHead, treeRoot) or self.isSubPath(linkedListHead, treeRoot.left) or  self.isSubPath(linkedListHead, treeRoot.right)

    def hasPathStartingFromNode(self, currentListNode: Optional[ListNode], currentTreeNode: Optional[TreeNode]) -> bool:
        if currentListNode is None:
            return True
        if currentTreeNode is None:
            return False
        return currentListNode.val == currentTreeNode.val and  (self.hasPathStartingFromNode(currentListNode.next, currentTreeNode.left) or self.hasPathStartingFromNode(currentListNode.next, currentTreeNode.right))