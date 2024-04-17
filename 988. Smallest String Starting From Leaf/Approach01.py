from typing import *

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self) -> None:
        self.result = ''

    def dfs(self, root, current):
        if root is None:
            return
        
        current = chr(root.val + ord('a')) + current

        if root.left is None and root.right is None:
            if self.result == '' or self.result > current:
                self.result = current
            return
        self.dfs(root.left, current)
        self.dfs(root.right, current)        
            
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        self.dfs(root, '')
        return self.result
