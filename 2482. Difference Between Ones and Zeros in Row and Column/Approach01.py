from typing import *

class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        row = len(grid)
        col = len(grid[0])

        result = [[0] * col for _ in range(row)]
        onesRow = [i.count(1) for i in grid]
        onesCol = [j.count(1) for j in zip(*grid)]

        for i in range(row):
            for j in range(col):
                result[i][j] = onesRow[i] + onesCol[j] - (col - onesRow[i]) - (row - onesCol[j])

        return result