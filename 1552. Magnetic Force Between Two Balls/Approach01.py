from typing import List

class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()

        left = 1
        right = position[-1] - position[0]

        while left < right:
            mid = right - (right - left) // 2
            if self.num_balls(position, mid) >= m:  # There're too many balls.
                left = mid
            else:  # There're too few balls.
                right = mid - 1

        return left

    def num_balls(self, position: List[int], force: int) -> int:
        balls = 0
        prev_position = -force
        for pos in position:
            if pos - prev_position >= force:
                balls += 1
                prev_position = pos
        return balls
