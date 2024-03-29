from typing import *

class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        max_element_index = []
        result = 0
        max_val = max(nums)

        for i in range(n):
            if(nums[i] == max_val):
               max_element_index.append(i)
            size = len(max_element_index)
            if(size>=k):
                last_index = max_element_index[size-k]
                result += (last_index + 1)
        return result        