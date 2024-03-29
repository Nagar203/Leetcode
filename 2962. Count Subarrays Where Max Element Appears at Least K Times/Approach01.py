from typing import *

class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        max_element = max(nums)
        i, j = 0, 0
        result, max_cnt = 0, 0
        mp = {}
        n = len(nums)

        while(j<n):
            if(nums[j] == max_element):
                max_cnt += 1
            while(max_cnt >= k):
                result += (n-j)
                if(nums[i] == max_element):
                    max_cnt -= 1
                i += 1
            j += 1
        return result