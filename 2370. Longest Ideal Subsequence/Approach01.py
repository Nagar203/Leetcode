from typing import *

class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        t = [0] * 26

        for c in s:
            i = ord(c) - ord("a")
            t[i] = 1 + self.solve(t, i, k)

        return max(t)

    def solve(self, t: List[int], i: int, k: int) -> int:
        first = max(0, i - k)
        last = min(25, i + k)
        maxReachable = 0
        for j in range(first, last + 1):
            maxReachable = max(maxReachable, t[j])
        return maxReachable
