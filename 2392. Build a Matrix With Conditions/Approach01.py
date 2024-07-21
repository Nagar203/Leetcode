from collections import deque, defaultdict
from typing import List

class Solution:
    def buildMatrix(self, k: int, rowConditions: List[List[int]], colConditions: List[List[int]]) -> List[List[int]]:
        # Perform topological sorting for rows
        rowOrder = self.topologicalSort(rowConditions, k)
        if not rowOrder:
            return []

        # Perform topological sorting for columns
        colOrder = self.topologicalSort(colConditions, k)
        if not colOrder:
            return []

        # Initialize the result matrix
        matrix = [[0] * k for _ in range(k)]
        nodeToRowIndex = [0] * (k + 1)

        # Map nodes to their row indices based on rowOrder
        for row, node in enumerate(rowOrder):
            nodeToRowIndex[node] = row

        # Fill in the matrix based on the column order
        for col, node in enumerate(colOrder):
            row = nodeToRowIndex[node]
            matrix[row][col] = node

        return matrix

    def topologicalSort(self, conditions: List[List[int]], n: int) -> List[int]:
        sortedOrder = []                     # To store the topological order
        adjList = defaultdict(list)          # Adjacency list for the graph
        inDegrees = [0] * (n + 1)            # In-degree count for each node
        zeroInDegreeNodes = deque()          # Queue for nodes with zero in-degree

        # Build the graph from conditions
        for from_node, to_node in conditions:
            adjList[from_node].append(to_node)
            inDegrees[to_node] += 1

        # Initialize the queue with nodes having zero in-degree
        for i in range(1, n + 1):
            if inDegrees[i] == 0:
                zeroInDegreeNodes.append(i)

        # Perform Kahn's algorithm for topological sorting
        while zeroInDegreeNodes:
            node = zeroInDegreeNodes.popleft()
            sortedOrder.append(node)
            for neighbor in adjList[node]:
                inDegrees[neighbor] -= 1
                if inDegrees[neighbor] == 0:
                    zeroInDegreeNodes.append(neighbor)

        # Check if a valid topological sort was found
        return sortedOrder if len(sortedOrder) == n else []
