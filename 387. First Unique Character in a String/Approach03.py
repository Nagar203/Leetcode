from typing import *
import collections
import sys

class Solution:
    def firstUniqChar(self, s: str) -> int:
        f = collections.Counter(s)
        result = sys.maxsize
        
        filter_freq = [ ord(k) - ord('a') for k,v in f.items() if v==1]  
        n = len(filter_freq)
        
        for i in range(n):            
                index = s.index(chr(filter_freq[i] + ord('a')))
                result = min(index, result)
        if(result == sys.maxsize):
            return -1
        return result