#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int magicSquareCount = 0;

        // Traverse through the grid, considering each 3x3 section
        for (int row = 0; row + 2 < grid.size(); ++row) {
            for (int col = 0; col + 2 < grid[0].size(); ++col) {
                if (isMagicSquare(grid, row, col)) {
                    ++magicSquareCount;
                }
            }
        }

        return magicSquareCount;
    }

private:
    // Function to check if a 3x3 section starting at (row, col) is a magic square
    bool isMagicSquare(const vector<vector<int>>& grid, int row, int col) {
        // Check that all values are between 1 and 9 and unique
        vector<int> digits(10, 0);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int value = grid[row + i][col + j];
                if (value < 1 || value > 9 || ++digits[value] > 1) {
                    return false;
                }
            }
        }

        // Check the sums of the rows, columns, and diagonals
        int sum1 = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
        int sum2 = grid[row + 1][col] + grid[row + 1][col + 1] + grid[row + 1][col + 2];
        int sum3 = grid[row + 2][col] + grid[row + 2][col + 1] + grid[row + 2][col + 2];

        int sum4 = grid[row][col] + grid[row + 1][col] + grid[row + 2][col];
        int sum5 = grid[row][col + 1] + grid[row + 1][col + 1] + grid[row + 2][col + 1];
        int sum6 = grid[row][col + 2] + grid[row + 1][col + 2] + grid[row + 2][col + 2];

        int diagonal1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int diagonal2 = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];

        // Return true if all sums are equal
        return (sum1 == sum2 && sum2 == sum3 &&
                sum3 == sum4 && sum4 == sum5 &&
                sum5 == sum6 && sum6 == diagonal1 &&
                diagonal1 == diagonal2);
    }
};
