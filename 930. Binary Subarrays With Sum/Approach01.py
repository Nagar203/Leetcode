from typing import *

class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        n = len(nums)
        result = 0
        cummu_sum = 0
        mp = {}
        mp[0] = 1

        for i in range(n):
            cummu_sum += nums[i]
            check = cummu_sum - goal
            if(check in mp):
                result += mp[check]
                
            if cummu_sum in mp:
                mp[cummu_sum] += 1
            else:
                mp[cummu_sum] = 1
        return result