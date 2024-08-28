from typing import List

class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        subIslandsCount = 0

        for row in range(len(grid2)):
            for col in range(len(grid2[0])):
                if grid2[row][col] == 1:
                    subIslandsCount += self.exploreIsland(grid1, grid2, row, col)
        
        return subIslandsCount

    def exploreIsland(self, grid1: List[List[int]], grid2: List[List[int]], row: int, col: int) -> int:
        if row < 0 or row == len(grid1) or col < 0 or col == len(grid2[0]):
            return 1
        if grid2[row][col] != 1:
            return 1

        grid2[row][col] = 2  # Mark as visited
        return (
            self.exploreIsland(grid1, grid2, row + 1, col) &
            self.exploreIsland(grid1, grid2, row - 1, col) &
            self.exploreIsland(grid1, grid2, row, col + 1) &
            self.exploreIsland(grid1, grid2, row, col - 1) &
            grid1[row][col]
        )
