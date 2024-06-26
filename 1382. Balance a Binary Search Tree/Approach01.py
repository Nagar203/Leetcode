from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        nums = []
        self.inorder_traversal(root, nums)
        return self.build_balanced_bst(nums, 0, len(nums) - 1)

    def inorder_traversal(self, root: Optional[TreeNode], nums: List[int]) -> None:
        if root is None:
            return
        self.inorder_traversal(root.left, nums)
        nums.append(root.val)
        self.inorder_traversal(root.right, nums)

    def build_balanced_bst(self, nums: List[int], left: int, right: int) -> Optional[TreeNode]:
        if left > right:
            return None
        mid = (left + right) // 2
        root = TreeNode(nums[mid])
        root.left = self.build_balanced_bst(nums, left, mid - 1)
        root.right = self.build_balanced_bst(nums, mid + 1, right)
        return root
