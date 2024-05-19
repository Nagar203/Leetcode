from typing import *

class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        max_sum = sum(max(num, num ^ k) for num in nums)
        changedCount = sum((num ^ k) > num for num in nums)
        
        if changedCount % 2 == 0:
            return max_sum
        
        min_change_diff = min(abs(num - (num ^ k)) for num in nums)
        return max_sum - min_change_diff