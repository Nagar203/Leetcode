import heapq
import math
from typing import List

class Solution:
    def maxKelements(self, numbers: List[int], k: int) -> int:
        result = 0
        negNumbers = [-n for n in numbers]
        heapq.heapify(negNumbers)

        for _ in range(k):
            currentNumber = -heapq.heappop(negNumbers)
            result += currentNumber
            heapq.heappush(negNumbers, -math.ceil(currentNumber / 3))

        return result