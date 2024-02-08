from typing import *

class Solution:
    def numSquares(self, n: int) -> int:
        t = [1000000]*(n+1)
        t[0] = 0

        for i in range(1, n+1):
            for j in range(1, int(i**0.5) + 1):
                t[i] = min(t[i], 1 + t[i - j*j])
        return t[n]
