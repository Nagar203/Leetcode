from typing import *

class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        mp = {}
        i = 0
        j = 0
        result = 0

        while j < n:
            mp[nums[j]] = mp.get(nums[j], 0) + 1
            while (i < j and mp[nums[j]] > k):
                mp[nums[i]] -= 1
                if mp[nums[i]] == 0:
                    del mp[nums[i]]
                i += 1
            result = max(result, j - i + 1) 
            j += 1

        return result