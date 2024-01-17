from typing import *
import collections

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        data = [0]*2001
        
        for d in arr:
            if(d < 0):
                d = d + 1000            
            data[d] += 1

        data.sort()
        n = len(data)

        for i in range(1,n):
            if(data[i] == data[i-1] and data[i] != 0):
                return False
        return True
