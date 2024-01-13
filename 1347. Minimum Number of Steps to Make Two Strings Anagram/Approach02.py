from typing import *
import collections

class Solution:
    def minSteps(self, s: str, t: str) -> int:
        freq = [0] * 26
        n = len(s)

        for i in range(n):
            freq[ord(s[i]) - ord('a')] += 1
            freq[ord(t[i]) - ord('a')] -= 1

        result = 0

        for i in range(26):
            if freq[i] > 0:
                result += freq[i]

        return result
