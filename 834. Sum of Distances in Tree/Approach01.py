from collections import defaultdict


class Solution:
    def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
        result = [0] * n
        count = [1] * n
        tree = defaultdict(set)

        for edge in edges:
            u, v = edge
            tree[u].add(v)
            tree[v].add(u)

        self.post_order(tree, 0, -1, count, result)
        self.pre_order(tree, 0, -1, count, result)
        return result

    def post_order(self, tree, node, parent, count, result):
        for child in tree[node]:
            if child == parent:
                continue
            self.post_order(tree, child, node, count, result)
            count[node] += count[child]
            result[node] += result[child] + count[child]

    def pre_order(self, tree, node, parent, count, result):
        for child in tree[node]:
            if child == parent:
                continue
            result[child] = result[node] - count[child] + (len(tree) - count[child])
            self.pre_order(tree, child, node, count, result)
