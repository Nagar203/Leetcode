from typing import *

class Solution:
    def countSquares(self, matrix: list[list[int]]) -> int:
        rows = len(matrix)
        cols = len(matrix[0])

        # Update the matrix with the size of square that can be formed at each cell
        for row in range(rows):
            for col in range(cols):
                if matrix[row][col] == 1 and row > 0 and col > 0:
                    matrix[row][col] += min(matrix[row - 1][col - 1], matrix[row - 1][col], matrix[row][col - 1])

        # Calculate the total number of squares
        return sum(sum(currentRow) for currentRow in matrix)