#include <unordered_set>
#include <vector>

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();
        int maxMovesCount = 0;

        // dp[i][j] represents the maximum number of moves you can perform from (i, j)
        vector<vector<int>> maxMovesGrid(rows, vector<int>(cols));

        for (int col = cols - 2; col >= 0; --col) {
            for (int row = 0; row < rows; ++row) {
                if (grid[row][col + 1] > grid[row][col])
                    maxMovesGrid[row][col] = 1 + maxMovesGrid[row][col + 1];
                if (row > 0 && grid[row - 1][col + 1] > grid[row][col])
                    maxMovesGrid[row][col] = max(maxMovesGrid[row][col], 1 + maxMovesGrid[row - 1][col + 1]);
                if (row + 1 < rows && grid[row + 1][col + 1] > grid[row][col])
                    maxMovesGrid[row][col] = max(maxMovesGrid[row][col], 1 + maxMovesGrid[row + 1][col + 1]);
            }
        }

        for (int row = 0; row < rows; ++row)
            maxMovesCount = max(maxMovesCount, maxMovesGrid[row][0]);

        return maxMovesCount;
    }
};
