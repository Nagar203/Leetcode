from typing import List

class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        total_time = 0

        for i in range(1, len(points)):
            x1, y1 = points[i-1]
            x2, y2 = points[i]

            dx = abs(x2 - x1)
            dy = abs(y2 - y1)

            diagonal_distance = min(dx, dy)

            remaining_dx = dx - diagonal_distance
            remaining_dy = dy - diagonal_distance

            move_time = diagonal_distance + remaining_dx + remaining_dy

            total_time += move_time

        return total_time