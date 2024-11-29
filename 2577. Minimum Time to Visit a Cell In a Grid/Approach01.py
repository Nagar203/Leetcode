from heapq import heappush, heappop

class Solution:
    def minimumTime(self, grid: list[list[int]]) -> int:
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1

        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        rows, cols = len(grid), len(grid[0])
        minHeap = [(0, 0, 0)]  # (currentTime, row, col)
        visited = [[False] * cols for _ in range(rows)]
        visited[0][0] = True

        while minHeap:
            currentTime, row, col = heappop(minHeap)
            if row == rows - 1 and col == cols - 1:
                return currentTime
            for dx, dy in directions:
                newRow, newCol = row + dx, col + dy
                if newRow < 0 or newRow == rows or newCol < 0 or newCol == cols:
                    continue
                if visited[newRow][newCol]:
                    continue
                waitTime = (grid[newRow][newCol] - currentTime) % 2 == 0
                nextTime = max(currentTime + 1, grid[newRow][newCol] + (1 if waitTime else 0))
                heappush(minHeap, (nextTime, newRow, newCol))
                visited[newRow][newCol] = True

        raise Exception("Path to the destination was not found.")