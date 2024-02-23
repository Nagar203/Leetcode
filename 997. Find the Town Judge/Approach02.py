from typing import *
import collections 

class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        if(len(trust)==0 and n==1):
            return 1
        
        first = []
        second = []
        
        for nums in trust:
            first.append(nums[0])
            second.append(nums[1])
        
        f = collections.Counter(second)
        for key, val in f.items():
            if((n-1)<= val <=n):
                if key not in first:
                    return key
        return -1