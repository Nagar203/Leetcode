from typing import *

class Solution:
    def matrixScore(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        result = 0

        for row in grid:
            if row[0] == 0:
                self.flip(row)

        for j in range(n):
            if self.onesColCount(grid, j) * 2 < m:
                self.flipCol(grid, j)

        for row in grid:
            result += self.binary(row)

        return result

    def flip(self, row):
        for i in range(len(row)):
            row[i] ^= 1

    def onesColCount(self, grid, j):
        ones = 0
        for i in range(len(grid)):
            ones += grid[i][j]
        return ones

    def flipCol(self, grid, j):
        for i in range(len(grid)):
            grid[i][j] ^= 1

    def binary(self, row):
        res = row[0]
        for j in range(1, len(row)):
            res = res * 2 + row[j]
        return res