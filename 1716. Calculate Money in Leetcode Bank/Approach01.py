from typing import List

class Solution:
    def totalMoney(self, n: int) -> int:
        start = 1
        result = 0

        while n > 0:
            for i in range(7):
                if n > 0:
                    result += start + i
                    n -= 1
            start += 1

        return result