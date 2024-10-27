class Solution:
    def treeQueries(self, root: 'TreeNode', queries: list[int]) -> list[int]:
        result = []
        
        # Calculate heights for all nodes
        self.calculateHeights(root, 0, 0)

        # Retrieve the maximum height for each query
        for query in queries:
            result.append(self.nodeToMaxHeight[query])

        return result

    def __init__(self):
        # nodeToMaxHeight[nodeValue] stores the maximum height excluding the node with `nodeValue`
        self.nodeToMaxHeight = {}
        # nodeToHeight[nodeValue] stores the height of the node with `nodeValue`
        self.nodeToHeight = {}

    # Helper function to get the height of a node
    def getHeight(self, root: 'TreeNode') -> int:
        if not root:
            return 0
        if root.val in self.nodeToHeight:
            return self.nodeToHeight[root.val]
        self.nodeToHeight[root.val] = 1 + max(self.getHeight(root.left), self.getHeight(root.right))
        return self.nodeToHeight[root.val]

    # Recursive function to calculate heights and update maxHeight without the current node
    def calculateHeights(self, root: 'TreeNode', currentDepth: int, maxHeight: int):
        if not root:
            return
        self.nodeToMaxHeight[root.val] = maxHeight
        self.calculateHeights(root.left, currentDepth + 1, max(maxHeight, currentDepth + self.getHeight(root.right)))
        self.calculateHeights(root.right, currentDepth + 1, max(maxHeight, currentDepth + self.getHeight(root.left)))