#include <unordered_set>
#include <vector>

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Update the matrix with the size of square that can be formed at each
        // cell
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (matrix[row][col] == 1 && row > 0 && col > 0)
                    matrix[row][col] += min({matrix[row - 1][col - 1], matrix[row - 1][col],  matrix[row][col - 1]});
            }
        }

        // Calculate the total number of squares
        return accumulate(matrix.begin(), matrix.end(), 0, [](int totalSquares, const vector<int>& currentRow) {
            return totalSquares + accumulate(currentRow.begin(), currentRow.end(), 0); 
        });
    }
};