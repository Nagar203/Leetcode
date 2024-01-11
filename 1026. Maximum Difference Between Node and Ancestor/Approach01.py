from typing import *
import collections

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def get_node(self, root, max_val, min_val):
        if root == None:
            return abs(max_val-min_val)

        max_val = max(root.val, max_val)
        min_val = min(root.val, min_val)

        left_data = self.get_node(root.left, max_val, min_val)
        right_data = self.get_node(root.right, max_val, min_val)

        return max(left_data, right_data)

    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        return self.get_node(root, root.val, root.val)
        