from typing import *

class Solution:
    def maxMoves(self, grid: list[list[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        maxMovesCount = 0

        # maxMovesGrid[i][j] represents the maximum number of moves you can perform from (i, j)
        maxMovesGrid = [[0] * cols for _ in range(rows)]

        for col in range(cols - 2, -1, -1):
            for row in range(rows):
                if grid[row][col + 1] > grid[row][col]:
                    maxMovesGrid[row][col] = 1 + maxMovesGrid[row][col + 1]
                if row > 0 and grid[row - 1][col + 1] > grid[row][col]:
                    maxMovesGrid[row][col] = max(maxMovesGrid[row][col], 1 + maxMovesGrid[row - 1][col + 1])
                if row + 1 < rows and grid[row + 1][col + 1] > grid[row][col]:
                    maxMovesGrid[row][col] = max(maxMovesGrid[row][col], 1 + maxMovesGrid[row + 1][col + 1])

        for row in range(rows):
            maxMovesCount = max(maxMovesCount, maxMovesGrid[row][0])

        return maxMovesCount
