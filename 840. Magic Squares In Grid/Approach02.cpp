#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int magicSquareCount = 0;

        // Traverse through the grid, considering each 3x3 section
        for (int row = 0; row + 2 < grid.size(); ++row) {
            for (int col = 0; col + 2 < grid[0].size(); ++col) {
                // Check for basic properties: the center of the magic square must be 5
                if (grid[row][col] % 2 == 0 && grid[row + 1][col + 1] == 5) {
                    magicSquareCount += isMagicSquare(grid, row, col);
                }
            }
        }

        return magicSquareCount;
    }

private:
    // Function to check if a 3x3 section starting at (row, col) is a magic square
    int isMagicSquare(const vector<vector<int>>& grid, int row, int col) {
        string squarePattern;

        // Construct a string pattern based on the elements' positions in the grid
        for (const int position : {0, 1, 2, 5, 8, 7, 6, 3}) {
            squarePattern += to_string(grid[row + position / 3][col + position % 3]);
        }

        // Check if the pattern matches any of the two valid magic square patterns
        return string("4381672943816729").find(squarePattern) != string::npos ||
               string("9276183492761834").find(squarePattern) != string::npos;
    }
};
