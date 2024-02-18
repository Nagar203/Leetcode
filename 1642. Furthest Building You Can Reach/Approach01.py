from typing import *
import heapq

class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        
        n = len(heights)
        pq = []

        for i in range(1, n):
            diff = heights[i] - heights[i - 1]
            if diff >= 0:
                heapq.heappush(pq, diff)

                if len(pq) > ladders:
                    bricks -= heapq.heappop(pq)

                if bricks < 0:
                    return i - 1

        return n - 1

