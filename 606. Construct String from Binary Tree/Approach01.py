from typing import *

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        if root is None:
            return ''

        result = str(root.val)
        LEFT = self.tree2str(root.left)
        RIGHT = self.tree2str(root.right)

        if root.left is None and root.right is None:
            return result

        if root.left is None:
            return result + "()" + "(" + RIGHT + ")"

        if root.right is None:
            return result + "(" + LEFT + ")"

        return result + "("+ LEFT + ")" + "("+ RIGHT +")" 