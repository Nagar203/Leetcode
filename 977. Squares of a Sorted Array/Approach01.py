from typing import *

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        for i in range(n):
            nums[i] = (nums[i]*nums[i])
        nums.sort()
        return nums
