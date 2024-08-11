from typing import List

class Solution:
    # Direction array to facilitate grid traversal.
    directions = [-1, 0, 1, 0, -1]
    
    # Function to determine the minimum number of days required to disconnect the grid.
    def minDays(self, grid: List[List[int]]) -> int:
        # Initialize grid dimensions.
        self.numRows = len(grid)
        self.numCols = len(grid[0])
      
        # Check if the grid is already disconnected or completely connected.
        if self.countIslands(grid) != 1:
            return 0  # No day required if the grid is already disconnected.
      
        # Try removing each land cell to see if it isolates the grid.
        for row in range(self.numRows):
            for col in range(self.numCols):
                if grid[row][col] == 1:  # Check if the current cell is land.
                    grid[row][col] = 0  # Temporarily remove the land cell.
                    if self.countIslands(grid) != 1:
                        return 1  # If removing the cell disconnects the grid, return 1 day.
                    grid[row][col] = 1  # Restore the land cell.
      
        # If no single removal disconnects the grid, return 2 days as the required time.
        return 2

    # Helper function to count the number of islands (connected land components) in the grid.
    def countIslands(self, grid: List[List[int]]) -> int:
        islandCount = 0
        # Traverse the grid to identify islands.
        for row in range(self.numRows):
            for col in range(self.numCols):
                if grid[row][col] == 1:  # Start DFS if a land cell is found.
                    self.dfs(row, col, grid)
                    islandCount += 1  # Increment the island count after completing DFS.
        
        # Reset the grid to its original state after counting.
        for row in range(self.numRows):
            for col in range(self.numCols):
                if grid[row][col] == 2:
                    grid[row][col] = 1  # Restore the state from temporary 2 to land (1).
        
        return islandCount  # Return the total number of islands.

    # Depth-first search (DFS) to mark all cells of a connected component.
    def dfs(self, row: int, col: int, grid: List[List[int]]) -> None:
        grid[row][col] = 2  # Temporarily mark the cell to avoid revisiting.
        # Explore all four adjacent directions.
        for dir in range(4):
            newRow = row + self.directions[dir]
            newCol = col + self.directions[dir + 1]
            # Continue DFS if the adjacent cell is within bounds and is land.
            if 0 <= newRow < self.numRows and 0 <= newCol < self.numCols and grid[newRow][newCol] == 1:
                self.dfs(newRow, newCol, grid)