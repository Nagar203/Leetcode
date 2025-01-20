class Solution:
    def firstCompleteIndex(self, paintOrder: list[int], matrix: list[list[int]]) -> int:
        numRows = len(matrix)
        numCols = len(matrix[0])
        
        # paintedRows[i]: the count of painted cells in the i-th row
        paintedRows = [0] * numRows
        # paintedCols[j]: the count of painted cells in the j-th column
        paintedCols = [0] * numCols
        # cellToRow[cellValue]: the row index of cellValue in the matrix
        cellToRow = [0] * (numRows * numCols + 1)
        # cellToCol[cellValue]: the column index of cellValue in the matrix
        cellToCol = [0] * (numRows * numCols + 1)

        # Map each cell value to its corresponding row and column in the matrix
        for row in range(numRows):
            for col in range(numCols):
                cellToRow[matrix[row][col]] = row
                cellToCol[matrix[row][col]] = col

        # Process the painting order and track row/column completion
        for index, cellValue in enumerate(paintOrder):
            row = cellToRow[cellValue]
            col = cellToCol[cellValue]
            
            paintedRows[row] += 1  # Increment the count for the row
            paintedCols[col] += 1  # Increment the count for the column
            
            if paintedRows[row] == numCols:  # Check if the row is completely painted
                return index
            if paintedCols[col] == numRows:  # Check if the column is completely painted
                return index

        raise RuntimeError("A valid solution is guaranteed, this should not occur.")