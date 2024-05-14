from typing import *

class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        def solve(i: int, j: int) -> int:
            if i < 0 or j < 0 or i == len(grid) or j == len(grid[0]):
                return 0

            if grid[i][j] == 0:
                return 0

            gold = grid[i][j]
            grid[i][j] = 0 
            max_path = max(solve(i + 1, j), solve(i - 1, j), solve(i, j + 1), solve(i, j - 1))
            grid[i][j] = gold
            return gold + max_path

        return max(solve(i, j) for i in range(len(grid)) for j in range(len(grid[0])))