from typing import *

from typing import List

class Solution:
    def checkRecord(self, n: int) -> int:
        MOD = 10**9 + 7
        t = [[0] * 3 for _ in range(2)]
        t[0][0] = 1

        while n > 0:
            prev = [row[:] for row in t]  # Make a copy of t
            t[0][0] = (prev[0][0] + prev[0][1] + prev[0][2]) % MOD
            t[0][1] = prev[0][0]
            t[0][2] = prev[0][1]
            t[1][0] = (prev[0][0] + prev[0][1] + prev[0][2] + prev[1][0] + prev[1][1] + prev[1][2]) % MOD
            t[1][1] = prev[1][0]
            t[1][2] = prev[1][1]
            n -= 1

        result = sum(sum(row) for row in t) % MOD
        return result