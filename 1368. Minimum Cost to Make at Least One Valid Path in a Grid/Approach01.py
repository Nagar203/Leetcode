from typing import List
from collections import deque

class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        costMemo = [[-1] * cols for _ in range(rows)]
        bfsQueue = deque()

        # Start DFS from the top-left corner with an initial cost of 0
        self.dfs(grid, 0, 0, 0, bfsQueue, costMemo)

        # Process the BFS queue to explore all possible paths
        currentCost = 1
        while bfsQueue:
            for _ in range(len(bfsQueue)):
                currentRow, currentCol = bfsQueue.popleft()
                for dx, dy in self.directions:
                    self.dfs(grid, currentRow + dx, currentCol + dy, currentCost, bfsQueue, costMemo)
            currentCost += 1

        # Return the minimum cost to reach the bottom-right corner
        return costMemo[-1][-1]

    # Directions: right, left, down, up
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    def dfs(self, grid: List[List[int]], row: int, col: int, currentCost: int,
            bfsQueue: deque, costMemo: List[List[int]]) -> None:
        # Check for out-of-bounds indices
        if not (0 <= row < len(grid)) or not (0 <= col < len(grid[0])):
            return
        # If this cell has already been visited with a lower cost, skip it
        if costMemo[row][col] != -1:
            return

        # Mark the current cell with the current cost
        costMemo[row][col] = currentCost
        # Add the current cell to the BFS queue
        bfsQueue.append((row, col))

        # Move in the direction indicated by the current cell's value
        dx, dy = self.directions[grid[row][col] - 1]
        self.dfs(grid, row + dx, col + dy, currentCost, bfsQueue, costMemo)
