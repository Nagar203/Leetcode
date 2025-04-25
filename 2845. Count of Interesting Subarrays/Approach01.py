from typing import List
from collections import defaultdict

class Solution:
    def countInterestingSubarrays(self, nums: List[int], modulo: int, k: int) -> int:
        totalSubarrays = 0
        prefixModCount = 0
        prefixFrequency = defaultdict(int)
        prefixFrequency[0] = 1

        for num in nums:
            if num % modulo == k:
                prefixModCount = (prefixModCount + 1) % modulo

            target = (prefixModCount - k + modulo) % modulo
            totalSubarrays += prefixFrequency[target]
            prefixFrequency[prefixModCount] += 1

        return totalSubarrays