from typing import *

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        self.result = 0
        self.dfs(root)
        return self.result

    def dfs(self, root: TreeNode) -> int:
        if root is None:
            return 0

        l = self.dfs(root.left)
        r = self.dfs(root.right)
        self.result += abs(l) + abs(r)
        return (root.val - 1) + l + r
