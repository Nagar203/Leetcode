import heapq
from typing import List, Tuple

class Solution:
    def dijkstra(self, graph: List[List[Tuple[int, int]]], src: int, dst: int, k: int) -> int:
        dist = [[float('inf')] * (k + 2) for _ in range(len(graph))]
        min_heap = []
        
        dist[src][k + 1] = 0
        heapq.heappush(min_heap, (dist[src][k + 1], src, k + 1))
        
        while min_heap:
            d, u, stops = heapq.heappop(min_heap)
            if u == dst:
                return d
            if stops == 0:
                continue
            for v, w in graph[u]:
                if d + w < dist[v][stops - 1]:
                    dist[v][stops - 1] = d + w
                    heapq.heappush(min_heap, (dist[v][stops - 1], v, stops - 1))
        
        return -1
    
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        graph = [[] for _ in range(n)]
        
        for flight in flights:
            u, v, w = flight
            graph[u].append((v, w))
        
        return self.dijkstra(graph, src, dst, k)