from typing import *

class Solution:
    def spiralMatrixIII(self, numRows: int, numCols: int, startRow: int, startCol: int) -> List[List[int]]:
        # Direction vectors: right, down, left, up
        xDirections = [1, 0, -1, 0]
        yDirections = [0, 1, 0, -1]
        
        # Resultant matrix with the starting point
        result = [[startRow, startCol]]
        
        # Loop until we fill the matrix
        i = 0
        while len(result) < numRows * numCols:
            for step in range(i // 2 + 1):
                # Move in the current direction
                startRow += yDirections[i % 4]
                startCol += xDirections[i % 4]
                
                # Check if the new position is within the bounds
                if 0 <= startRow < numRows and 0 <= startCol < numCols:
                    result.append([startRow, startCol])
            i += 1
        
        return result