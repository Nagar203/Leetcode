from collections import defaultdict

class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:

        if n == 1 or not edges:
            return [0]
        
        result = []
        graph = defaultdict(set)
        
        for edge in edges:
            u, v = edge[0], edge[1]
            graph[u].add(v)
            graph[v].add(u)
        
        for label, children in graph.items():
            if len(children) == 1:
                result.append(label)
        
        while n > 2:
            n -= len(result)
            next_leaves = []
            for leaf in result:
                u = graph[leaf].pop()
                graph[u].remove(leaf)
                if len(graph[u]) == 1:
                    next_leaves.append(u)
            result = next_leaves
        
        return result
