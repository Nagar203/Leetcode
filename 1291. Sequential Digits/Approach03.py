from typing import List
from collections import deque

class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        result = []
        q = deque()

        for i in range(1, 9):
            q.append(i)

        while q:
            val = q.popleft()

            if val > high:
                return result

            if low <= val <= high:
                result.append(val)

            next_val = val % 10 + 1
            if next_val <= 9:
                q.append(val * 10 + next_val)

        return result
