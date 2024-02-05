from typing import *
import collections
import sys

class Solution:
    def firstUniqChar(self, s: str) -> int:
        f = collections.Counter(s)
        result = sys.maxsize
        
        for key, val in f.items():
            if val == 1:
                index = s.index(key)
                result = min(index, result)
        if(result == sys.maxsize):
            return -1
        return result