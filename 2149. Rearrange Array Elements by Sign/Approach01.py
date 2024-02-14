from typing import *

class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        pos = [i for i in nums if(i>0)]
        neg = [i for i in nums if(i<0)]
        result = []
        n = len(nums)

        for i in range(n//2):
            result.append(pos[i])
            result.append(neg[i])
        
        return result
