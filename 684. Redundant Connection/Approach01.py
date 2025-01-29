class UnionFind:
    def __init__(self, size: int):
        self.parent = list(range(size))  # Initialize each node as its own parent
        self.rank = [0] * size  # Rank for union by rank optimization

    def unionByRank(self, node1: int, node2: int) -> bool:
        root1 = self.find(node1)
        root2 = self.find(node2)

        if root1 == root2:
            return False  # Cycle detected

        # Union by rank
        if self.rank[root1] < self.rank[root2]:
            self.parent[root1] = root2
        elif self.rank[root1] > self.rank[root2]:
            self.parent[root2] = root1
        else:
            self.parent[root1] = root2
            self.rank[root2] += 1

        return True

    def find(self, node: int) -> int:
        if self.parent[node] != node:
            self.parent[node] = self.find(self.parent[node])  # Path compression
        return self.parent[node]


class Solution:
    def findRedundantConnection(self, edges: list[list[int]]) -> list[int]:
        unionFind = UnionFind(len(edges) + 1)

        for node1, node2 in edges:
            if not unionFind.unionByRank(node1, node2):  # If adding this edge forms a cycle
                return [node1, node2]

        raise Exception("No redundant connection found")
