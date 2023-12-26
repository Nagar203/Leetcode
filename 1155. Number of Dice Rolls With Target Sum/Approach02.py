from typing import *
import sys

class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        MOD = 10**9 + 7
        t = [[0] * (target + 1) for _ in range(n + 1)]
        t[0][0] = 1

        for i in range(1, n + 1):
            for j in range(1, target + 1):
                result = 0
                for face in range(1, k + 1):
                    if j >= face:
                        result = (result + t[i - 1][j - face]) % MOD
                t[i][j] = result

        return t[n][target]