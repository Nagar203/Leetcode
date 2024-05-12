from typing import *

class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        row = len(grid)       
        result = []

        for i in range(row-2):
            temp_result = []
            for j in range(row-2):
                val = max(grid[i][j], grid[i][j+1], grid[i][j+2], grid[i+1][j], grid[i+1][j+1], grid[i+1][j+2], grid[i+2][j], grid[i+2][j+1], grid[i+2][j+2])
                temp_result.append(val)
            result.append(temp_result)

        return result