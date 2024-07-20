#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSums, vector<int>& colSums) {
        const int numRows = rowSums.size();
        const int numCols = colSums.size();
        vector<vector<int>> resultMatrix(numRows, vector<int>(numCols));

        for (int row = 0; row < numRows; ++row)
            for (int col = 0; col < numCols; ++col) {
                resultMatrix[row][col] = min(rowSums[row], colSums[col]);
                rowSums[row] -= resultMatrix[row][col];
                colSums[col] -= resultMatrix[row][col];
            }

        return resultMatrix;
    }
};
