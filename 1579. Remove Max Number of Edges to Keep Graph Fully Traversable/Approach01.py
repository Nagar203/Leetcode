from typing import *

class UnionFind:
    def __init__(self, n):
        self.count = n
        self.id = list(range(n))
        self.rank = [0] * n

    def union_by_rank(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        if root_u == root_v:
            return False
        if self.rank[root_u] < self.rank[root_v]:
            self.id[root_u] = root_v
        elif self.rank[root_u] > self.rank[root_v]:
            self.id[root_v] = root_u
        else:
            self.id[root_u] = root_v
            self.rank[root_v] += 1
        self.count -= 1
        return True

    def get_count(self):
        return self.count

    def find(self, u):
        if self.id[u] != u:
            self.id[u] = self.find(self.id[u])  # Path compression
        return self.id[u]


class Solution:
    def maxNumEdgesToRemove(self, n, edges):
        alice = UnionFind(n)
        bob = UnionFind(n)
        required_edges = 0

        # Greedily put type 3 edges in the front.
        edges.sort(key=lambda x: -x[0])

        for edge in edges:
            type = edge[0]
            u = edge[1] - 1
            v = edge[2] - 1
            if type == 3:  # Can be traversed by Alice and Bob.
                if alice.union_by_rank(u, v) | bob.union_by_rank(u, v):
                    required_edges += 1
            elif type == 2:  # Can be traversed by Bob.
                if bob.union_by_rank(u, v):
                    required_edges += 1
            elif type == 1:  # Can be traversed by Alice.
                if alice.union_by_rank(u, v):
                    required_edges += 1

        return len(edges) - required_edges if alice.get_count() == 1 and bob.get_count() == 1 else -1