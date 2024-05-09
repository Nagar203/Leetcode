from typing import *

class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        result = 0
        decremented = 0

        happiness.sort(reverse=True)

        for i in range(k):
            result += max(0, happiness[i] - decremented)
            decremented += 1

        return result