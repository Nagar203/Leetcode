from typing import *
import sys

class Solution:
    def firstUniqChar(self, s: str) -> int:
        f = [0]*26
        result = sys.maxsize

        for i in s:
            f[ord(i) - ord('a')] += 1
        
        for i in range(26):
            if f[i] == 1:
                index = s.index(chr(ord('a') + i))
                result = min(index, result)
        if(result == sys.maxsize):
            return -1
        return result