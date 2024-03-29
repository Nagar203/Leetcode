from typing import *

class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        mp = {}
        i = 0
        j = 0
        result = 0
        culprit = 0

        while j < n:
            mp[nums[j]] = mp.get(nums[j], 0) + 1
            if(mp[nums[j]] == k + 1):
                culprit += 1

            if(culprit > 0):
                mp[nums[i]] -= 1
                if(mp[nums[i]] == k):
                    culprit -= 1
                i += 1
                
            if(culprit == 0):    
                result = max(result, j - i + 1) 
            j += 1
        return result