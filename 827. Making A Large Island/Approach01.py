class Solution:
    def largestIsland(self, grid: list[list[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        maxIslandSize = 0
        componentSizes = [0, 0]  # Sizes of connected components (starting from 2)
        
        # Assign a unique component ID (starting from 2) to each island and store its size
        componentId = 2
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    componentSizes.append(self.paint(grid, i, j, componentId))
                    componentId += 1
        
        # Try converting each 0 into 1 and calculate the largest possible island
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 0:
                    neighborIds = {
                        self.getComponentId(grid, i + 1, j),
                        self.getComponentId(grid, i - 1, j),
                        self.getComponentId(grid, i, j + 1),
                        self.getComponentId(grid, i, j - 1)
                    }
                    maxIslandSize = max(maxIslandSize, 1 + self.getTotalSize(neighborIds, componentSizes))

        return maxIslandSize if maxIslandSize > 0 else rows * cols

    def paint(self, grid: list[list[int]], i: int, j: int, componentId: int) -> int:
        if i < 0 or i == len(grid) or j < 0 or j == len(grid[0]) or grid[i][j] != 1:
            return 0
        grid[i][j] = componentId
        return 1 + self.paint(grid, i + 1, j, componentId) + self.paint(grid, i - 1, j, componentId) + \
               self.paint(grid, i, j + 1, componentId) + self.paint(grid, i, j - 1, componentId)

    def getComponentId(self, grid: list[list[int]], i: int, j: int) -> int:
        if i < 0 or i == len(grid) or j < 0 or j == len(grid[0]):
            return 0
        return grid[i][j]

    def getTotalSize(self, neighborIds: set[int], componentSizes: list[int]) -> int:
        return sum(componentSizes[componentId] for componentId in neighborIds)
