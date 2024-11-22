#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& binaryMatrix) {
        const int numRows = binaryMatrix.size();
        const int numCols = binaryMatrix[0].size();
        int maxEqualRows = 0;
        vector<int> flippedRow(numCols);
        unordered_set<int> processedRows;

        for (int currentRow = 0; currentRow < numRows; ++currentRow) {
            if (processedRows.contains(currentRow))
                continue;

            int rowCount = 0;

            for (int col = 0; col < numCols; ++col)
                flippedRow[col] = 1 ^ binaryMatrix[currentRow][col];

            for (int checkRow = 0; checkRow < numRows; ++checkRow) {
                if (binaryMatrix[checkRow] == binaryMatrix[currentRow] || binaryMatrix[checkRow] == flippedRow) {
                    processedRows.insert(checkRow);
                    ++rowCount;
                }
            }

            maxEqualRows = max(maxEqualRows, rowCount);
        }

        return maxEqualRows;
    }
};