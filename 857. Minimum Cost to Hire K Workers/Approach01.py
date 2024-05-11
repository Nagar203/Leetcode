import heapq
from typing import List

class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:

        workers = sorted(zip(quality, wage), key=lambda x: x[1] / x[0])
        min_cost = float("inf")
        total_quality = 0
        max_heap = []

        for q, w in workers:
            total_quality += q
            heapq.heappush(max_heap, -q)

            if len(max_heap) > k:
                total_quality += heapq.heappop(max_heap)
                
            if len(max_heap) == k:
                min_cost = min(min_cost, w / q * total_quality)

        return min_cost
