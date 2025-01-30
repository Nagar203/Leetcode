from collections import deque
from typing import List

class UnionFind:
    def __init__(self, size: int):
        self.parent = list(range(size))  # Initialize each node as its own parent
        self.rank = [0] * size  # Rank for union by rank optimization

    def unionByRank(self, node1: int, node2: int):
        root1 = self.find(node1)
        root2 = self.find(node2)

        if root1 == root2:
            return

        # Union by rank
        if self.rank[root1] < self.rank[root2]:
            self.parent[root1] = root2
        elif self.rank[root1] > self.rank[root2]:
            self.parent[root2] = root1
        else:
            self.parent[root1] = root2
            self.rank[root2] += 1

    def find(self, node: int) -> int:
        if self.parent[node] != node:
            self.parent[node] = self.find(self.parent[node])  # Path compression
        return self.parent[node]


class Solution:
    def magnificentSets(self, numNodes: int, edges: List[List[int]]) -> int:
        adjacencyList = [[] for _ in range(numNodes)]
        unionFind = UnionFind(numNodes)
        rootToMaxGroupSize = {}

        # Build adjacency list and perform union-find operations
        for node1, node2 in edges:
            node1 -= 1
            node2 -= 1
            adjacencyList[node1].append(node2)
            adjacencyList[node2].append(node1)
            unionFind.unionByRank(node1, node2)

        # Perform BFS to determine the maximum valid group size
        for i in range(numNodes):
            maxGroupSize = self.bfs(adjacencyList, i)
            if maxGroupSize == -1:
                return -1  # Odd cycle detected

            root = unionFind.find(i)
            rootToMaxGroupSize[root] = max(rootToMaxGroupSize.get(root, 0), maxGroupSize)

        return sum(rootToMaxGroupSize.values())

    def bfs(self, adjacencyList: List[List[int]], startNode: int) -> int:
        depth = 0
        nodeQueue = deque([startNode])
        nodeDepthMap = {startNode: 1}

        while nodeQueue:
            depth += 1
            for _ in range(len(nodeQueue)):
                currentNode = nodeQueue.popleft()
                for neighbor in adjacencyList[currentNode]:
                    if neighbor not in nodeDepthMap:
                        nodeQueue.append(neighbor)
                        nodeDepthMap[neighbor] = depth + 1
                    elif nodeDepthMap[neighbor] == depth:
                        return -1  # Odd-length cycle detected

        return depth