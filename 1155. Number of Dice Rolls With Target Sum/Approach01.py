from typing import *

class Solution:
    def __init__(self):
        self.MOD = 10**9 + 7
        self.t = [[-1] * 1001 for _ in range(31)]

    def solve(self, n, k, target):
        if target < 0:
            return 0
        if self.t[n][target] != -1:
            return self.t[n][target]
        if n == 0:
            return int(target == 0)

        result = 0
        for face in range(1, k + 1):
            result = (result + self.solve(n - 1, k, target - face)) % self.MOD

        self.t[n][target] = result
        return result

    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        for row in self.t:
            for i in range(len(row)):
                row[i] = -1

        return self.solve(n, k, target)