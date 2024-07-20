from typing import List

class Solution:
    def restoreMatrix(self, rowSums: List[int], colSums: List[int]) -> List[List[int]]:
        numRows = len(rowSums)
        numCols = len(colSums)
        resultMatrix = [[0] * numCols for _ in range(numRows)]

        for row in range(numRows):
            for col in range(numCols):
                resultMatrix[row][col] = min(rowSums[row], colSums[col])
                rowSums[row] -= resultMatrix[row][col]
                colSums[col] -= resultMatrix[row][col]

        return resultMatrix