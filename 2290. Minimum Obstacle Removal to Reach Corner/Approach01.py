from heapq import heappop, heappush
from typing import List, Tuple

class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        minHeap: List[Tuple[int, int, int]] = []  # (distance, row, col)
        minDistance = [[float('inf')] * cols for _ in range(rows)]

        heappush(minHeap, (grid[0][0], 0, 0))
        minDistance[0][0] = grid[0][0]

        while minHeap:
            currentDistance, currentRow, currentCol = heappop(minHeap)

            if currentRow == rows - 1 and currentCol == cols - 1:
                return currentDistance

            for dx, dy in directions:
                nextRow = currentRow + dx
                nextCol = currentCol + dy

                if nextRow < 0 or nextRow >= rows or nextCol < 0 or nextCol >= cols:
                    continue

                newDistance = currentDistance + grid[nextRow][nextCol]
                if newDistance < minDistance[nextRow][nextCol]:
                    minDistance[nextRow][nextCol] = newDistance
                    heappush(minHeap, (newDistance, nextRow, nextCol))

        return minDistance[rows - 1][cols - 1]