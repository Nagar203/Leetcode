from typing import *

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        data = Counter(nums)

        red = data[0]
        white = data[1]
        blue = data[2]

        nums.clear()
        nums.extend([0]*red)
        nums.extend([1]*white)
        nums.extend([2]*blue)
