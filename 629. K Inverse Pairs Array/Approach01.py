from typing import *

class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        MOD = 10**9+7
        t = [[0] * (k + 1) for _ in range(n + 1)]

        for i in range(n + 1):
            t[i][0] = 1

        for i in range(1, n + 1):
            for j in range(1, k + 1):
                t[i][j] = (t[i][j - 1] + t[i - 1][j]) % MOD
                if j - i >= 0:
                    t[i][j] = (t[i][j] - t[i - 1][j - i] + MOD) % MOD

        return t[n][k]