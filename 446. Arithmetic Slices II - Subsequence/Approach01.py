from typing import *

class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        result = 0
        mp = [{} for _ in range(n)]

        for i in range(n):
            for j in range(i):
                d = nums[i] - nums[j]
                cnt = mp[j].get(d, 0)
                mp[i][d] = mp[i].get(d, 0) + cnt + 1
                result += cnt

        return result

