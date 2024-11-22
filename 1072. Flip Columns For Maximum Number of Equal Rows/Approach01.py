from typing import List

class Solution:
    def maxEqualRowsAfterFlips(self, binaryMatrix: List[List[int]]) -> int:
        numRows = len(binaryMatrix)
        numCols = len(binaryMatrix[0])
        maxEqualRows = 0
        processedRows = set()

        for currentRow in range(numRows):
            if currentRow in processedRows:
                continue

            rowCount = 0
            flippedRow = [1 ^ binaryMatrix[currentRow][col] for col in range(numCols)]

            for checkRow in range(numRows):
                if (binaryMatrix[checkRow] == binaryMatrix[currentRow] or 
                        binaryMatrix[checkRow] == flippedRow):
                    processedRows.add(checkRow)
                    rowCount += 1

            maxEqualRows = max(maxEqualRows, rowCount)

        return maxEqualRows