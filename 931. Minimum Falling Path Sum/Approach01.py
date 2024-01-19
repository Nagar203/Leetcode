from typing import *
import collections

class Solution:
    def solve(self, matrix):
        m = len(matrix)
        t = [[0] * m for _ in range(m)]

        for col in range(m):
            t[0][col] = matrix[0][col]

        for row in range(1, m):
            for col in range(m):
                t[row][col] = matrix[row][col] + min(t[row-1][col], t[row-1][max(0, col-1)], t[row-1][min(m-1, col+1)])

        return min(t[-1])

    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        return self.solve(matrix)
