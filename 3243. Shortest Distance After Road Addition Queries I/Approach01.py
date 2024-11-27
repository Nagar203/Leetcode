import collections

class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: list[list[int]]) -> list[int]:
        result = []
        distances = list(range(n))
        adjacencyList = [[] for _ in range(n)]

        # Initialize the graph (adjacency list)
        for i in range(n - 1):
            adjacencyList[i].append(i + 1)

        # Process each query
        for u, v in queries:
            adjacencyList[u].append(v)
            # Update distance and perform BFS if necessary
            if distances[u] + 1 < distances[v]:
                distances[v] = distances[u] + 1
                self._bfs(adjacencyList, v, distances)
            result.append(distances[n - 1])

        return result

    def _bfs(self, adjacencyList: list[list[int]], startNode: int, distances: list[int]) -> None:
        queue = collections.deque([startNode])
        while queue:
            currentNode = queue.popleft()
            for neighbor in adjacencyList[currentNode]:
                if distances[currentNode] + 1 < distances[neighbor]:
                    distances[neighbor] = distances[currentNode] + 1
                    queue.append(neighbor)