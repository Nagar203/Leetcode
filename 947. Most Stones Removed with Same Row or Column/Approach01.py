from typing import List, Set

class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        islandCount = 0  # To count the number of connected components (islands)
        adjacencyList = [[] for _ in range(len(stones))]  # Graph represented as an adjacency list
        visitedNodes: Set[int] = set()  # Set to keep track of visited nodes

        # Building the graph by connecting nodes that are in the same row or column
        for i in range(len(stones)):
            for j in range(i + 1, len(stones)):
                if stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]:
                    adjacencyList[i].append(j)
                    adjacencyList[j].append(i)

        # DFS to count the number of islands (connected components)
        for i in range(len(stones)):
            if i not in visitedNodes:  # If node i is not visited
                self.exploreConnectedComponent(adjacencyList, i, visitedNodes)
                islandCount += 1  # Increment the count of islands

        # The answer is the total number of stones minus the number of connected components
        return len(stones) - islandCount

    def exploreConnectedComponent(self, adjacencyList: List[List[int]], node: int, visitedNodes: Set[int]) -> None:
        for adjacentNode in adjacencyList[node]:
            if adjacentNode not in visitedNodes:  # If adjacentNode is not visited
                visitedNodes.add(adjacentNode)
                self.exploreConnectedComponent(adjacencyList, adjacentNode, visitedNodes)  # Continue DFS