from typing import *

class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        n = len(nums)
        missing_val = -1
        repeat_val = -1

        for i in range(n):
            if nums[abs(nums[i])-1] < 0:
                repeat_val = abs(nums[i])
            else:
                nums[abs(nums[i])-1] *= (-1)

        for i in range(n):
            if(nums[i] >0):
                missing_val = i +1
                break

        return [repeat_val, missing_val]