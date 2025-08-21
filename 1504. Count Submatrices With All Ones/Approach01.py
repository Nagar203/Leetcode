class Solution:
    def numSubmat(self, mat: list[list[int]]) -> int:
        rowCount = len(mat)
        colCount = len(mat[0])
        totalSubmatrices = 0

        for startRow in range(rowCount):
            validCols = [1] * colCount
            for currentRow in range(startRow, rowCount):
                for col in range(colCount):
                    validCols[col] &= mat[currentRow][col]
                totalSubmatrices += self.count(validCols)

        return totalSubmatrices

    def count(self, validCols: list[int]) -> int:
        submatrixCount = 0
        consecutiveOnes = 0
        for val in validCols:
            consecutiveOnes = 0 if val == 0 else consecutiveOnes + 1
            submatrixCount += consecutiveOnes
        return submatrixCount
