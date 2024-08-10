from typing import *

class Solution:
    def regionsBySlashes(self, grid):
        gridSize = len(grid)
        # upscaledGrid is a 3x size grid to represent slashes more precisely
        upscaledGrid = [[0] * (gridSize * 3) for _ in range(gridSize * 3)]

        # Fill the upscaled grid based on the slashes in the original grid
        for row in range(gridSize):
            for col in range(gridSize):
                if grid[row][col] == '/':
                    upscaledGrid[row * 3][col * 3 + 2] = 1
                    upscaledGrid[row * 3 + 1][col * 3 + 1] = 1
                    upscaledGrid[row * 3 + 2][col * 3] = 1
                elif grid[row][col] == '\\':
                    upscaledGrid[row * 3][col * 3] = 1
                    upscaledGrid[row * 3 + 1][col * 3 + 1] = 1
                    upscaledGrid[row * 3 + 2][col * 3 + 2] = 1

        regionCount = 0

        # Perform DFS to find connected regions
        for row in range(gridSize * 3):
            for col in range(gridSize * 3):
                if upscaledGrid[row][col] == 0:
                    self.dfs(upscaledGrid, row, col)
                    regionCount += 1

        return regionCount

    def dfs(self, upscaledGrid, row, col):
        # Boundary and visited checks
        if row < 0 or row == len(upscaledGrid) or col < 0 or col == len(upscaledGrid[0]):
            return
        if upscaledGrid[row][col] != 0:
            return

        upscaledGrid[row][col] = 2  # Mark as visited
        self.dfs(upscaledGrid, row + 1, col)  # Down
        self.dfs(upscaledGrid, row - 1, col)  # Up
        self.dfs(upscaledGrid, row, col + 1)  # Right
        self.dfs(upscaledGrid, row, col - 1)  # Left
