from typing import *
 
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def solve(self, root, current):
        if(root == None):
            return 0
        current = current*10 + root.val
        if(root.left == None and root.right == None):
            return current
        left = self.solve(root.left, current)
        right = self.solve(root.right, current)
        return (left + right)
    
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        result = self.solve(root, 0)
        return result    