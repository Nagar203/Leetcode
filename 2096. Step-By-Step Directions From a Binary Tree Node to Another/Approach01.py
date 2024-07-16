class Solution:
    def getDirections(self, root: TreeNode, startValue: int, destValue: int) -> str:
        currentPath = []
        pathToStart = []
        pathToDest = []

        # Find the lowest common ancestor and start DFS from there.
        self.dfs(self.findLCA(root, startValue, destValue), startValue, destValue, currentPath, pathToStart, pathToDest)

        # Construct the path by going up to the common ancestor and then down to the destination.
        return 'U' * len(pathToStart) + ''.join(pathToDest)

    # Function to find the lowest common ancestor (LCA) of two nodes.
    def findLCA(self, root: TreeNode, p: int, q: int) -> TreeNode:
        if root is None or root.val == p or root.val == q:
            return root

        leftLCA = self.findLCA(root.left, p, q)
        rightLCA = self.findLCA(root.right, p, q)

        if leftLCA is not None and rightLCA is not None:
            return root

        return leftLCA if leftLCA is not None else rightLCA

    # DFS to find paths from the LCA to the start and destination nodes.
    def dfs(self, root: TreeNode, startValue: int, destValue: int, currentPath: list, pathToStart: list, pathToDest: list):
        if root is None:
            return

        if root.val == startValue:
            pathToStart.extend(currentPath)
        if root.val == destValue:
            pathToDest.extend(currentPath)

        # Traverse left subtree
        currentPath.append('L')
        self.dfs(root.left, startValue, destValue, currentPath, pathToStart, pathToDest)
        currentPath.pop()

        # Traverse right subtree
        currentPath.append('R')
        self.dfs(root.right, startValue, destValue, currentPath, pathToStart, pathToDest)
        currentPath.pop()