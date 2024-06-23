from typing import List

class Solution:
    def get_left_side_array(self, height: List[int], n: int) -> List[int]:
        left_max = [0] * n
        left_max[0] = height[0]
        for i in range(1, n):
            left_max[i] = max(left_max[i - 1], height[i])
        return left_max

    def get_right_side_array(self, height: List[int], n: int) -> List[int]:
        right_max = [0] * n
        right_max[n - 1] = height[n - 1]
        for i in range(n - 2, -1, -1):
            right_max[i] = max(right_max[i + 1], height[i])
        return right_max

    def trap(self, height: List[int]) -> int:
        n = len(height)

        left_max = self.get_left_side_array(height, n)
        right_max = self.get_right_side_array(height, n)

        total_water = 0
        for i in range(n):
            h = min(left_max[i], right_max[i]) - height[i]
            total_water += max(h, 0)
        
        return total_water
