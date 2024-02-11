from typing import List

class Solution:
    def __init__(self):
        self.m = 0
        self.n = 0
        self.t = [[[-1 for _ in range(71)] for _ in range(71)] for _ in range(71)]

    def solve(self, grid, row, col1, col2):
        if row >= self.m:
            return 0

        if(self.t[row][col1][col2] != -1):
            return self.t[row][col1][col2]

        cherry = grid[row][col1]
        if col1 != col2:
            cherry += grid[row][col2]

        direction = [-1, 0, 1]
        result = 0
        for i in direction:
            for j in direction:
                if 0 <= col1 + i < self.n and 0 <= col2 + j < self.n:
                    result = max(result, self.solve(grid, row + 1, col1 + i, col2 + j))
        self.t[row][col1][col2] = result + cherry
        return result + cherry

    def cherryPickup(self, grid: List[List[int]]) -> int:
        self.m = len(grid)
        self.n = len(grid[0])
        output = self.solve(grid, 0, 0, self.n - 1)
        return output
