from typing import *

class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        pos = 0
        neg = 1
        n = len(nums)
        result = [0]*n

        for num in nums:
            if(num>0):
                result[pos] = num
                pos += 2
                continue
            result[neg] = num
            neg += 2               
        
        return result
