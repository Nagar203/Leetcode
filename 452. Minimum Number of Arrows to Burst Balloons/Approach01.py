from typing import *
import math

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        result = 0
        arrow = -math.inf

        for point in sorted(points, key=lambda x: x[1]):
            if point[0] > arrow:
                result += 1
                arrow = point[1]

        return result