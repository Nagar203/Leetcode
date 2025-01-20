class Solution {
public:
    int firstCompleteIndex(vector<int>& paintOrder, vector<vector<int>>& matrix) {
        const int numRows = matrix.size();
        const int numCols = matrix[0].size();

        // paintedRows[i]: the count of painted cells in the i-th row
        vector<int> paintedRows(numRows);
        // paintedCols[j]: the count of painted cells in the j-th column
        vector<int> paintedCols(numCols);
        // cellToRow[cellValue]: the row index of cellValue in the matrix
        vector<int> cellToRow(numRows * numCols + 1);
        // cellToCol[cellValue]: the column index of cellValue in the matrix
        vector<int> cellToCol(numRows * numCols + 1);

        // Map each cell value to its corresponding row and column in the matrix
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                cellToRow[matrix[row][col]] = row;
                cellToCol[matrix[row][col]] = col;
            }
        }

        // Process the painting order and track row/column completion
        for (int index = 0; index < paintOrder.size(); ++index) {
            int row = cellToRow[paintOrder[index]];
            int col = cellToCol[paintOrder[index]];

            if (++paintedRows[row] ==
                numCols) // Check if the row is completely painted
                return index;
            if (++paintedCols[col] ==
                numRows) // Check if the column is completely painted
                return index;
        }

        throw; // This should not happen as the problem guarantees a valid solution
    }
};