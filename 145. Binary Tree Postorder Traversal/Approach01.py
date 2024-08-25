from typing import *

class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        self.traversePostorder(root, result)
        return result

    def traversePostorder(self, node, result):
        if node is None:
            return

        self.traversePostorder(node.left, result)
        self.traversePostorder(node.right, result)
        result.append(node.val)