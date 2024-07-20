from typing import *

class Solution:
    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        # Iterate through each row in the matrix
        for row in matrix:
            # Find the index of the minimum element in the current row
            minElementIndex = row.index(min(row))

            # Check if the minimum element in the row is the maximum element in its column
            if row[minElementIndex] == self.getMaxOfColumn(matrix, minElementIndex):
                return [row[minElementIndex]]
        
        # Return an empty list if no lucky number is found
        return []

    # Helper function to find the maximum element in a specified column
    def getMaxOfColumn(self, matrix: List[List[int]], colIndex: int) -> int:
        maxElement = 0
        # Iterate through each row to find the maximum element in the column
        for row in matrix:
            maxElement = max(maxElement, row[colIndex])
        return maxElement
