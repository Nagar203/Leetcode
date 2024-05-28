from typing import *

class Solution:
    def equalSubstring(self, s: str, t: str, max_cost: int) -> int:
        j = 0
        for i in range(len(s)):
            max_cost -= abs(ord(s[i]) - ord(t[i]))
            if max_cost < 0:
                max_cost += abs(ord(s[j]) - ord(t[j]))
                j += 1

        return len(s) - j
