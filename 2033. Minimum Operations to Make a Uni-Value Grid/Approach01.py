from typing import List

class Solution:
    def minOperations(self, grid: List[List[int]], stepSize: int) -> int:
        flattenedGrid = [value for row in grid for value in row]

        if any((value - flattenedGrid[0]) % stepSize for value in flattenedGrid):
            return -1

        totalOperations = 0

        flattenedGrid.sort()
        medianValue = flattenedGrid[len(flattenedGrid) // 2]

        for value in flattenedGrid:
            totalOperations += abs(value - medianValue) // stepSize

        return totalOperations
