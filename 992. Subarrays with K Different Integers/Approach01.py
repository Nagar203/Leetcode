from typing import *
from collections import defaultdict

class Solution:
    def slidingWindow(self, nums, k):
        element_count = defaultdict(int)
        n = len(nums)
        start = 0
        end = 0
        result = 0
        
        while end < n:
            element_count[nums[end]] += 1
            
            while len(element_count) > k:
                element_count[nums[start]] -= 1
                if element_count[nums[start]] == 0:
                    del element_count[nums[start]]
                start += 1
            
            result += (end - start + 1)
            end += 1
        
        return result
    
    def subarraysWithKDistinct(self, nums, k):
        return self.slidingWindow(nums, k) - self.slidingWindow(nums, k - 1)
