from typing import *

class Solution:
    def flipEquiv(self, tree1: TreeNode, tree2: TreeNode) -> bool:
        if tree1 is None:
            return tree2 is None
        if tree2 is None:
            return tree1 is None
        if tree1.val != tree2.val:
            return False
        
        # Check for flip equivalence in both flipped and non-flipped scenarios
        return (self.flipEquiv(tree1.left, tree2.left) and 
                self.flipEquiv(tree1.right, tree2.right)) or \
               (self.flipEquiv(tree1.left, tree2.right) and 
                self.flipEquiv(tree1.right, tree2.left))