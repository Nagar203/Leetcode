from typing import *

class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        length = len(heights)
        sorted_heights = heights.copy()
        sorted_heights.sort()
        cnt = 0

        for i in range(length):
            if heights[i] != sorted_heights[i]:
                cnt += 1
        return cnt
