from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        nums.sort()
        n1 = nums[-1] - 1
        n2 = nums[-2] - 1
        return (n1*n2)