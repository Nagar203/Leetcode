from typing import *
import collections

class Solution:
    def minSteps(self, s: str, t: str) -> int:
        s_freq = [0] * 26
        t_freq = [0] * 26
        n = len(s)

        for i in range(n):
            s_freq[ord(s[i]) - ord('a')] += 1
            t_freq[ord(t[i]) - ord('a')] += 1

        result = 0

        for i in range(26):
            if s_freq[i] > t_freq[i]:
                result += s_freq[i] - t_freq[i]

        return result
