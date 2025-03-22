from typing import List

class UnionFind:
    def __init__(self, size: int):
        self.parent = list(range(size))
        self.rank = [0] * size
        self.componentSize = [1] * size
        self.edgeCount = [0] * size

    def unionByRank(self, node1: int, node2: int):
        root1 = self.find(node1)
        root2 = self.find(node2)
        self.edgeCount[root1] += 1

        if root1 == root2:
            return

        if self.rank[root1] < self.rank[root2]:
            self.parent[root1] = root2
            self.edgeCount[root2] += self.edgeCount[root1]
            self.componentSize[root2] += self.componentSize[root1]
        elif self.rank[root1] > self.rank[root2]:
            self.parent[root2] = root1
            self.edgeCount[root1] += self.edgeCount[root2]
            self.componentSize[root1] += self.componentSize[root2]
        else:
            self.parent[root1] = root2
            self.edgeCount[root2] += self.edgeCount[root1]
            self.componentSize[root2] += self.componentSize[root1]
            self.rank[root2] += 1

    def find(self, node: int) -> int:
        if self.parent[node] != node:
            self.parent[node] = self.find(self.parent[node])
        return self.parent[node]

    def isCompleteComponent(self, node: int) -> bool:
        return self.componentSize[node] * (self.componentSize[node] - 1) // 2 == self.edgeCount[node]


class Solution:
    def countCompleteComponents(self, totalNodes: int, edges: List[List[int]]) -> int:
        completeComponents = 0
        uf = UnionFind(totalNodes)
        uniqueParents = set()

        for node1, node2 in edges:
            uf.unionByRank(node1, node2)

        for node in range(totalNodes):
            root = uf.find(node)
            if root not in uniqueParents:
                uniqueParents.add(root)
                if uf.isCompleteComponent(root):
                    completeComponents += 1

        return completeComponents
