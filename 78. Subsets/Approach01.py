from typing import *

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []

        def solve(s: int, path: List[int]) -> None:
            result.append(path)

            for i in range(s, len(nums)):
                solve(i + 1, path + [nums[i]])

        solve(0, [])
        return result