from typing import *

class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        i, j = 0, 0
        product = 1
        result = 0
        n = len(nums)

        if(k<= 1):
            return 0

        while(j<n):
            product *= nums[j]

            while(product >= k):
                product = (product/nums[i])
                i += 1
            result += (j-i+1)
            j += 1
        return result
