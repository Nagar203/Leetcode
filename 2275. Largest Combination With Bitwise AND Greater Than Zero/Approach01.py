from typing import List

class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        maxBitPosition = 24
        maxCount = 0

        for bitPosition in range(maxBitPosition):
            currentBitCount = 0
            for candidate in candidates:
                if (candidate >> bitPosition) & 1:
                    currentBitCount += 1
            maxCount = max(maxCount, currentBitCount)

        return maxCount