from typing import *


class Solution:
    def scoreOfString(self, s: str) -> int:
        result = 0
        n = len(s)
        for i in range(n-1):
            result += abs(ord(s[i]) - ord(s[i + 1]))
        return result