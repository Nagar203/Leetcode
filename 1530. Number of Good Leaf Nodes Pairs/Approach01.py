from typing import *

class Solution:
    def countPairs(self, root: TreeNode, distance: int) -> int:
        self.pairCount = 0
        self.dfs(root, distance)
        return self.pairCount

    def dfs(self, root: TreeNode, maxDistance: int) -> List[int]:
        distances = [0] * (maxDistance + 1)  # {distance: the number of leaf nodes}
        if root is None:
            return distances
        if root.left is None and root.right is None:
            distances[0] = 1
            return distances

        leftDistances = self.dfs(root.left, maxDistance)
        rightDistances = self.dfs(root.right, maxDistance)

        for leftDist in range(maxDistance):
            for rightDist in range(maxDistance):
                if leftDist + rightDist + 2 <= maxDistance:
                    self.pairCount += leftDistances[leftDist] * rightDistances[rightDist]

        for dist in range(maxDistance):
            distances[dist + 1] = leftDistances[dist] + rightDistances[dist]

        return distances