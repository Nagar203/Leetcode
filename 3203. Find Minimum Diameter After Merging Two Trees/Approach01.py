class Solution:
    def minimumDiameterAfterMerge(self, treeEdges1: list[list[int]], treeEdges2: list[list[int]]) -> int:
        diameterTree1 = self.getDiameter(treeEdges1)
        diameterTree2 = self.getDiameter(treeEdges2)
        combinedDiameter = (diameterTree1 + 1) // 2 + (diameterTree2 + 1) // 2 + 1
        return max(diameterTree1, diameterTree2, combinedDiameter)

    def getDiameter(self, treeEdges: list[list[int]]) -> int:
        totalNodes = len(treeEdges) + 1
        adjacencyList = [[] for _ in range(totalNodes)]

        for edge in treeEdges:
            node1, node2 = edge
            adjacencyList[node1].append(node2)
            adjacencyList[node2].append(node1)

        maxTreeDiameter = [0]  # Using a list to mimic pass-by-reference behavior
        self.calculateMaxDepth(adjacencyList, 0, -1, maxTreeDiameter)
        return maxTreeDiameter[0]

    def calculateMaxDepth(self, adjacencyList: list[list[int]], currentNode: int, parentNode: int, maxTreeDiameter: list[int]) -> int:
        maxSubtreeDepth1 = 0
        maxSubtreeDepth2 = 0

        for neighbor in adjacencyList[currentNode]:
            if neighbor == parentNode:
                continue
            currentSubtreeDepth = self.calculateMaxDepth(adjacencyList, neighbor, currentNode, maxTreeDiameter)
            if currentSubtreeDepth > maxSubtreeDepth1:
                maxSubtreeDepth2 = maxSubtreeDepth1
                maxSubtreeDepth1 = currentSubtreeDepth
            elif currentSubtreeDepth > maxSubtreeDepth2:
                maxSubtreeDepth2 = currentSubtreeDepth

        maxTreeDiameter[0] = max(maxTreeDiameter[0], maxSubtreeDepth1 + maxSubtreeDepth2)
        return 1 + maxSubtreeDepth1