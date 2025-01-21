class Solution:
    def gridGame(self, grid: list[list[int]]) -> int:
        numCols = len(grid[0])  # Number of columns in the grid
        minPoints = float('inf')  # Minimum points robot 2 can collect
        upperRowSum = sum(grid[0])  # Total points in the upper row
        lowerRowSum = 0  # Points collected in the lower row

        # Iterate through each column as the split point
        for col in range(numCols):
            upperRowSum -= grid[0][col]  # Deduct the points collected from the upper row
            # Calculate the maximum points robot 2 can collect at this split point
            minPoints = min(minPoints, max(upperRowSum, lowerRowSum))
            lowerRowSum += grid[1][col]  # Add the points collected from the lower row

        return minPoints