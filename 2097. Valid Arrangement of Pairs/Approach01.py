from collections import defaultdict, deque
from typing import List

class Solution:
    def validArrangement(self, pairs: List[List[int]]) -> List[List[int]]:
        result = []
        adjacencyList = defaultdict(deque)
        outDegree = defaultdict(int)
        inDegree = defaultdict(int)

        # Build graph and track in-degrees and out-degrees
        for startNode, endNode in pairs:
            adjacencyList[startNode].append(endNode)
            outDegree[startNode] += 1
            inDegree[endNode] += 1

        # Get the starting node for Eulerian path
        startNode = self.findStartNode(adjacencyList, outDegree, inDegree, pairs)

        # Perform Eulerian traversal
        self.eulerianTraversal(adjacencyList, startNode, result)

        # Reverse the result to get the correct order
        result.reverse()
        return result

    def findStartNode(self, adjacencyList, outDegree, inDegree, pairs):
        for node in adjacencyList:
            if outDegree[node] - inDegree[node] == 1:
                return node
        return pairs[0][0]  # Arbitrarily choose a node.

    def eulerianTraversal(self, adjacencyList, currentNode, result):
        nodeStack = adjacencyList[currentNode]
        while nodeStack:
            nextNode = nodeStack.popleft()
            self.eulerianTraversal(adjacencyList, nextNode, result)
            result.append([currentNode, nextNode])