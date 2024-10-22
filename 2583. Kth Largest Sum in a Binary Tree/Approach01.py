class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        levelSumList = []
        self.calculateLevelSums(root, 0, levelSumList)
        if len(levelSumList) < k:
            return -1

        # Find the k-th largest element using n-th element logic
        levelSumList.sort(reverse=True)
        return levelSumList[k - 1]

    def calculateLevelSums(self, node: TreeNode, currentLevel: int, levelSumList: list[int]) -> None:
        if node is None:
            return
        if len(levelSumList) == currentLevel:
            levelSumList.append(0)
        levelSumList[currentLevel] += node.val
        self.calculateLevelSums(node.left, currentLevel + 1, levelSumList)
        self.calculateLevelSums(node.right, currentLevel + 1, levelSumList)