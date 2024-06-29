from typing import *

class Solution:
    def getAncestors(self, numNodes: int, edges: List[List[int]]) -> List[List[int]]:
        ancestors = [[] for _ in range(numNodes)]  # Stores the ancestors for each node
        graph = [[] for _ in range(numNodes)]      # Adjacency list for the graph

        # Build the graph from edges
        for edge in edges:
            fromNode, toNode = edge
            graph[fromNode].append(toNode)

        # Perform DFS for each node to find all ancestors
        for currentNode in range(numNodes):
            visited = [False] * numNodes
            self.dfs(graph, currentNode, currentNode, visited, ancestors)

        return ancestors

    def dfs(self, graph: List[List[int]], currentNode: int, ancestor: int, visited: List[bool], ancestors: List[List[int]]):
        visited[currentNode] = True
        for neighbor in graph[currentNode]:
            if visited[neighbor]:
                continue
            ancestors[neighbor].append(ancestor)
            self.dfs(graph, neighbor, ancestor, visited, ancestors)