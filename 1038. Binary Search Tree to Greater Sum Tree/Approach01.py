class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        prefix_sum = 0

        def reversed_inorder_traversal(node: TreeNode):
            nonlocal prefix_sum
            if node is None:
                return

            reversed_inorder_traversal(node.right)

            node.val += prefix_sum
            prefix_sum = node.val

            reversed_inorder_traversal(node.left)

        reversed_inorder_traversal(root)
        return root