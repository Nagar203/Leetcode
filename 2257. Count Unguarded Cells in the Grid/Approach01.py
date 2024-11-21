from typing import List

class Solution:
    def countUnguarded(self, rows: int, cols: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        unguardedCount = 0
        grid = [[0] * cols for _ in range(rows)]
        leftGuard = [[0] * cols for _ in range(rows)]
        rightGuard = [[0] * cols for _ in range(rows)]
        upGuard = [[0] * cols for _ in range(rows)]
        downGuard = [[0] * cols for _ in range(rows)]

        # Mark guards and walls on the grid
        for guard in guards:
            grid[guard[0]][guard[1]] = 'G'

        for wall in walls:
            grid[wall[0]][wall[1]] = 'W'

        # Fill guard visibility from left and right
        for i in range(rows):
            lastSeen = 0
            for j in range(cols):
                lastSeen = self.updateGuardInfo(grid[i][j], lastSeen, leftGuard, i, j)
            lastSeen = 0
            for j in range(cols - 1, -1, -1):
                lastSeen = self.updateGuardInfo(grid[i][j], lastSeen, rightGuard, i, j)

        # Fill guard visibility from top and bottom
        for j in range(cols):
            lastSeen = 0
            for i in range(rows):
                lastSeen = self.updateGuardInfo(grid[i][j], lastSeen, upGuard, i, j)
            lastSeen = 0
            for i in range(rows - 1, -1, -1):
                lastSeen = self.updateGuardInfo(grid[i][j], lastSeen, downGuard, i, j)

        # Count unguarded cells
        for i in range(rows):
            for j in range(cols):
                if (grid[i][j] == 0 and leftGuard[i][j] != 'G' and 
                    rightGuard[i][j] != 'G' and upGuard[i][j] != 'G' and 
                    downGuard[i][j] != 'G'):
                    unguardedCount += 1

        return unguardedCount

    def updateGuardInfo(self, currentCell: str, lastSeen: str, guardInfo: List[List[str]], i: int, j: int) -> str:
        if currentCell in {'G', 'W'}:
            lastSeen = currentCell
        else:
            guardInfo[i][j] = lastSeen
        return lastSeen