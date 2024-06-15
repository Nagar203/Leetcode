import heapq
from typing import List

class T:
    def __init__(self, profit, capital):
        self.profit = profit
        self.capital = capital

    def __lt__(self, other):
        return self.capital < other.capital

class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        min_heap = []
        max_heap = []

        for i in range(len(capital)):
            heapq.heappush(min_heap, T(profits[i], capital[i]))

        for _ in range(k):
            while min_heap and min_heap[0].capital <= w:
                item = heapq.heappop(min_heap)
                heapq.heappush(max_heap, (-item.profit, item.capital))
            if not max_heap:
                break
            w += -heapq.heappop(max_heap)[0]

        return w
