from typing import *

class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        
        t = [1] * n
        prev_index = [-1] * n
        result = []

        last_index = 0
        max_length = 1

        for i in range(1, n):
            for j in range(i):
                if nums[i] % nums[j] == 0:
                    if t[i] < t[j] + 1:
                        t[i] = t[j] + 1
                        prev_index[i] = j
                    if t[i] > max_length:
                        max_length = t[i]
                        last_index = i

        while last_index != -1:
            result.append(nums[last_index])
            last_index = prev_index[last_index]

        return result
