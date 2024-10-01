from typing import *

class Solution:
    def canArrange(self, numbers: List[int], divisor: int) -> bool:
        remainderCount = [0] * divisor

        for number in numbers:
            number %= divisor
            remainderCount[number if number >= 0 else number + divisor] += 1

        if remainderCount[0] % 2 != 0:
            return False

        for i in range(1, divisor // 2 + 1):
            if remainderCount[i] != remainderCount[divisor - i]:
                return False

        return True