class Solution:
    def findMaxFish(self, grid: list[list[int]]) -> int:
        maxFish = 0  # Maximum fish that can be collected

        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if grid[row][col] > 0:
                    maxFish = max(maxFish, self.performDFS(grid, row, col))

        return maxFish

    def performDFS(self, grid: list[list[int]], row: int, col: int) -> int:
        # Check for out-of-bounds or water cell (value 0)
        if row < 0 or row >= len(grid) or col < 0 or col >= len(grid[0]) or grid[row][col] == 0:
            return 0

        fishCaught = grid[row][col]  # Fish caught at this cell
        grid[row][col] = 0  # Mark the cell as visited by setting it to 0

        # Recursively collect fish in all four directions
        return fishCaught + \
               self.performDFS(grid, row + 1, col) + \
               self.performDFS(grid, row - 1, col) + \
               self.performDFS(grid, row, col + 1) + \
               self.performDFS(grid, row, col - 1)