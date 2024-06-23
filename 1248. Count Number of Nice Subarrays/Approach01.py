from typing import List

class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        def atMost(k: int) -> int:
            count = 0
            i = 0
            odd_count = 0
            for j in range(len(nums)):
                if nums[j] % 2 == 1:
                    odd_count += 1
                while odd_count > k:
                    if nums[i] % 2 == 1:
                        odd_count -= 1
                    i += 1
                count += j - i + 1
            return count
        
        # Number of subarrays with exactly k odd numbers
        return atMost(k) - atMost(k - 1)
