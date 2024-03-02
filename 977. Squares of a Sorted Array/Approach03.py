from typing import *

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        i, j, k = 0, n-1, n-1
        result = [0]*n

        while(k>=0):
            a = nums[i]*nums[i]
            b = nums[j]*nums[j]
            if(a>b):
                result[k] = a
                i += 1
            else:
                result[k] = b
                j -= 1
            k -= 1
        return result