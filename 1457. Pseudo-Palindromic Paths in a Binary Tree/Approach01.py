from typing import *

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def solve(self, root, path, result):
        if not root:
            return
        if not root.left and not root.right:
            path ^= 1 << root.val
            if path & (path - 1) == 0:
                result[0] += 1
            return

        self.solve(root.left, path ^ 1 << root.val, result)
        self.solve(root.right, path ^ 1 << root.val, result)

    def pseudoPalindromicPaths(self, root: Optional[TreeNode]) -> int:
        result = [0]
        self.solve(root, 0, result)
        return result[0]