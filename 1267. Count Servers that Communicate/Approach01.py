class Solution:
    def countServers(self, grid: list[list[int]]) -> int:
        numRows = len(grid)
        numCols = len(grid[0])
        serverCount = 0
        rowCounts = [0] * numRows  # Number of servers in each row
        colCounts = [0] * numCols  # Number of servers in each column

        # Count the servers in each row and column
        for row in range(numRows):
            for col in range(numCols):
                if grid[row][col] == 1:
                    rowCounts[row] += 1
                    colCounts[col] += 1

        # Count servers that can communicate
        for row in range(numRows):
            for col in range(numCols):
                if grid[row][col] == 1 and (rowCounts[row] > 1 or colCounts[col] > 1):
                    serverCount += 1

        return serverCount
