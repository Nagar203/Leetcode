from typing import *
import collections

class Solution:
    def firstUniqChar(self, s: str) -> int:
        freq = collections.Counter(s)
        index = 0
        for ch in s:
            if(freq[ch] == 1):
                return index
            index += 1 
        return -1