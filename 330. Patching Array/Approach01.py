from typing import List

class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        patches_needed = 0  # Number of patches (numbers) we need to add
        nums_index = 0  # Current index in the nums list
        current_miss = 1  # The minimum sum in the range [1, n] that we might miss

        while current_miss <= n:
            if nums_index < len(nums) and nums[nums_index] <= current_miss:
                # If the current number in nums is less than or equal to current_miss,
                # add it to the range and move to the next number in nums
                current_miss += nums[nums_index]
                nums_index += 1
            else:
                # If the current number in nums is greater than current_miss,
                # we need to add current_miss itself to the range.
                # This action increases the range from [1, current_miss) to [1, 2 * current_miss).
                current_miss += current_miss
                patches_needed += 1

        return patches_needed
