from typing import List

class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        prefix_sum = 0
        prefix_sum_map = {0: -1}

        for i, num in enumerate(nums):
            prefix_sum += num
            remainder = prefix_sum % k

            if remainder in prefix_sum_map:
                if (i - prefix_sum_map[remainder] > 1):
                    return True
            else:
                prefix_sum_map[remainder] = i

        return False
