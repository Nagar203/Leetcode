from typing import *

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def solve(self, root, val, depth, current):
        if(root == None):
            return None
        if(current == depth - 1):
            temp_left = root.left
            temp_right = root.right

            root.left = TreeNode(val)
            root.right = TreeNode(val)

            root.left.left = temp_left
            root.right.right = temp_right

            return root
        root.left = self.solve(root.left, val, depth, current+1)
        root.right = self.solve(root.right, val, depth, current+1)
        return root

    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        if(depth == 1):
            temp = root
            new_node = TreeNode(val, temp, None)
            return new_node

        current = 1
        result = self.solve(root, val, depth, current)
        return result