from typing import List


class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        flips_needed = 0
        current_flips = 0

        for i in range(len(nums)):
            if i >= k and nums[i - k] == 2:
                current_flips -= 1
            if current_flips % 2 == nums[i]:
                if i + k > len(nums):
                    return -1
                flips_needed += 1
                current_flips += 1
                nums[i] = 2

        return flips_needed
