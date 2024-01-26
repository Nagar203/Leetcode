from typing import *

class Solution:
    def __init__(self):
        self.MOD = int(1e9) + 7
        self.t = [[[ -1 for _ in range(51)] for _ in range(52)] for _ in range(52)]

    def solve(self, m, n, max_move, start_row, start_col, area):
        if start_row < 0 or start_row >= m or start_col < 0 or start_col >= n:
            return 1
        if max_move == 0:
            return 0
        if self.t[start_row][start_col][max_move] != -1:
            return self.t[start_row][start_col][max_move]

        result = 0
        for a in area:
            result = (result + self.solve(m, n, max_move - 1, start_row + a[0], start_col + a[1], area)) % self.MOD
        self.t[start_row][start_col][max_move] = result
        return self.t[start_row][start_col][max_move]

    def findPaths(self, m: int, n: int, max_move: int, start_row: int, start_col: int) -> int:
        area = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        result = self.solve(m, n, max_move, start_row, start_col, area)
        return result