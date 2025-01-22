from collections import deque

class Solution:
    def highestPeak(self, isWater: list[list[int]]) -> list[list[int]]:
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        rows = len(isWater)
        cols = len(isWater[0])
        heights = [[-1] * cols for _ in range(rows)]
        cellsToProcess = deque()

        # Initialize queue with all water cells and set their height to 0
        for row in range(rows):
            for col in range(cols):
                if isWater[row][col] == 1:
                    cellsToProcess.append((row, col))
                    heights[row][col] = 0

        # Perform BFS to calculate the height of each land cell
        while cellsToProcess:
            currentRow, currentCol = cellsToProcess.popleft()

            for dx, dy in directions:
                newRow = currentRow + dx
                newCol = currentCol + dy

                # Skip invalid or already-processed cells
                if newRow < 0 or newRow >= rows or newCol < 0 or newCol >= cols:
                    continue
                if heights[newRow][newCol] != -1:
                    continue

                # Set height and add to queue
                heights[newRow][newCol] = heights[currentRow][currentCol] + 1
                cellsToProcess.append((newRow, newCol))

        return heights
