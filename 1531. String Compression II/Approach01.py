from typing import *

class Solution:
    def __init__(self):
        self.memo = {}

    def solve(self, s, i, prev, freq, k):
        if k < 0:
            return float('inf')

        if i >= len(s):
            return 0

        if (i, prev, freq, k) in self.memo:
            return self.memo[(i, prev, freq, k)]

        delete_char = self.solve(s, i + 1, prev, freq, k - 1)

        keep_char = 0

        if ord(s[i]) - ord('a') == prev:
            one_addition = 0
            if freq == 1 or freq == 9 or freq == 99:
                one_addition = 1
            keep_char = one_addition + self.solve(s, i + 1, prev, freq + 1, k)
        else:
            keep_char = 1 + self.solve(s, i + 1, ord(s[i]) - ord('a'), 1, k)

        self.memo[(i, prev, freq, k)] = min(delete_char, keep_char)
        return self.memo[(i, prev, freq, k)]

    def getLengthOfOptimalCompression(self, s, k):
        self.memo = {}
        return self.solve(s, 0, 26, 0, k)
