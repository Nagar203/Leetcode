from typing import *

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def solve(self, root, result):
        if root is None:
            return 0
        
        left_val = self.solve(root.left, result)
        right_val = self.solve(root.right, result)
        
        result[0] = max(result[0], left_val + right_val)
        temp_result = max(left_val, right_val)
        
        return temp_result + 1
    
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        
        result = [-1] 
        self.solve(root, result)
        return result[0]
