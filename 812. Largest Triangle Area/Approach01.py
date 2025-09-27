from typing import List

class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        maxArea = 0.0

        for pointA in points:
            for pointB in points:
                for pointC in points:
                    area = 0.5 * abs((pointB[0] - pointA[0]) * (pointC[1] - pointA[1]) -
                                     (pointC[0] - pointA[0]) * (pointB[1] - pointA[1]))
                    maxArea = max(maxArea, area)

        return maxArea
