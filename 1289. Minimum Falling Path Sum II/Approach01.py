from typing import *

class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        
        for i in range(1, n):
            two_min_num_and_indexs = self.solve(grid[i - 1])
            first_min_num, first_min_index = two_min_num_and_indexs[0]
            second_min_num, _ = two_min_num_and_indexs[1]
            for j in range(n):
                if j == first_min_index:
                    grid[i][j] += second_min_num
                else:
                    grid[i][j] += first_min_num
        
        return min(grid[-1])

    def solve(self, A: List[int]) -> List[Tuple[int, int]]:
        num_and_indexs = [(num, i) for i, num in enumerate(A)]
        num_and_indexs.sort()
        return [num_and_indexs[0], num_and_indexs[1]]
