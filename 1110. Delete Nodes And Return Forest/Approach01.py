from typing import List, Optional, Set
from collections import deque

class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        remaining_trees = []
        to_delete_set = set(to_delete)  # Create a set from to_delete list for quick lookup
        self.removeNodes(root, to_delete_set, True, remaining_trees)
        return remaining_trees

    def removeNodes(self, node: Optional[TreeNode], to_delete_set: Set[int], is_root: bool, remaining_trees: List[TreeNode]) -> Optional[TreeNode]:
        if node is None:
            return None

        # Check if the current node needs to be deleted
        is_deleted = node.val in to_delete_set

        # If the current node is a root and not deleted, add it to the result
        if is_root and not is_deleted:
            remaining_trees.append(node)

        # Recursively process the left and right subtrees
        node.left = self.removeNodes(node.left, to_delete_set, is_deleted, remaining_trees)
        node.right = self.removeNodes(node.right, to_delete_set, is_deleted, remaining_trees)

        # Return None if the node is deleted, otherwise return the node itself
        return None if is_deleted else node