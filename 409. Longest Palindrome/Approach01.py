from typing import *
import collections

class Solution:
    def longestPalindrome(self, s: str) -> int:
        result = 0
        count = collections.Counter(s)

        for c in count.values():
            result += c if c % 2 == 0 else c - 1

        hasOddCount = any(c % 2 == 1 for c in count.values())
        return result + hasOddCount
