from typing import *

class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        result = 0
        min_data = 0

        for num in sorted(nums):
            result += max(min_data - num, 0)
            min_data = max(min_data, num) + 1

        return result
