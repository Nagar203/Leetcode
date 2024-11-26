from typing import List

class Solution:
    def findChampion(self, numNodes: int, edges: List[List[int]]) -> int:
        potentialChampion = -1
        zeroInDegreeCount = 0
        inDegrees = [0] * numNodes

        # Calculate in-degrees for each node
        for edge in edges:
            targetNode = edge[1]
            inDegrees[targetNode] += 1

        # Identify nodes with zero in-degree
        for node in range(numNodes):
            if inDegrees[node] == 0:
                zeroInDegreeCount += 1
                potentialChampion = node

        # If more than one node has zero in-degree, no champion exists
        return -1 if zeroInDegreeCount > 1 else potentialChampion