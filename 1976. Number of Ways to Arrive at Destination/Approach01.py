from typing import List
import heapq

class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        # Build the graph
        graph = [[] for _ in range(n)]
        for road in roads:
            u, v, weight = road
            graph[u].append((v, weight))
            graph[v].append((u, weight))
        
        return self.dijkstra(graph, 0, n - 1)

    def dijkstra(self, graph: List[List[tuple]], source: int, destination: int) -> int:
        kMod = 1_000_000_007
        numberOfWays = [0] * len(graph)
        distances = [float('inf')] * len(graph)
        
        numberOfWays[source] = 1
        distances[source] = 0
        
        minHeap = []
        heapq.heappush(minHeap, (distances[source], source))
        
        while minHeap:
            currentDistance, currentNode = heapq.heappop(minHeap)
            
            if currentDistance > distances[currentNode]:
                continue
            
            for neighbor, weight in graph[currentNode]:
                if currentDistance + weight < distances[neighbor]:
                    distances[neighbor] = currentDistance + weight
                    numberOfWays[neighbor] = numberOfWays[currentNode]
                    heapq.heappush(minHeap, (distances[neighbor], neighbor))
                elif currentDistance + weight == distances[neighbor]:
                    numberOfWays[neighbor] += numberOfWays[currentNode]
                    numberOfWays[neighbor] %= kMod
        
        return numberOfWays[destination]
