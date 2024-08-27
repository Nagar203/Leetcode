import heapq
from typing import List

class Solution:
    def maxProbability(self, numNodes: int, edges: List[List[int]], successProbabilities: List[float], startNode: int, endNode: int) -> float:
        graph = [[] for _ in range(numNodes)]
        maxHeap = [(-1.0, startNode)]
        visited = [False] * numNodes

        for i in range(len(edges)):
            nodeA = edges[i][0]
            nodeB = edges[i][1]
            probability = successProbabilities[i]
            graph[nodeA].append((nodeB, probability))
            graph[nodeB].append((nodeA, probability))

        while maxHeap:
            currentProbability, currentNode = heapq.heappop(maxHeap)
            currentProbability = -currentProbability
            if currentNode == endNode:
                return currentProbability
            if visited[currentNode]:
                continue
            visited[currentNode] = True
            for adjacentNode, edgeProbability in graph[currentNode]:
                if not visited[adjacentNode]:
                    heapq.heappush(maxHeap, (-(currentProbability * edgeProbability), adjacentNode))

        return 0