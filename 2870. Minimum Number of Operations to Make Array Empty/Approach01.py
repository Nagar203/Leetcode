from typing import *
import collections

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        frequency_counter = collections.Counter(nums)
        
        if 1 in frequency_counter.values():
            return -1
        
        return sum((freq + 2) // 3 for freq in frequency_counter.values())