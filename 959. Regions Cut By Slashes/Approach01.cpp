#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        const int gridSize = grid.size();
        // upscaledGrid is a 3x size grid to represent slashes more precisely
        vector<vector<int>> upscaledGrid(gridSize * 3, vector<int>(gridSize * 3));

        // Fill the upscaled grid based on the slashes in the original grid
        for (int row = 0; row < gridSize; ++row) {
            for (int col = 0; col < gridSize; ++col) {
                if (grid[row][col] == '/') {
                    upscaledGrid[row * 3][col * 3 + 2] = 1;
                    upscaledGrid[row * 3 + 1][col * 3 + 1] = 1;
                    upscaledGrid[row * 3 + 2][col * 3] = 1;
                } else if (grid[row][col] == '\\') {
                    upscaledGrid[row * 3][col * 3] = 1;
                    upscaledGrid[row * 3 + 1][col * 3 + 1] = 1;
                    upscaledGrid[row * 3 + 2][col * 3 + 2] = 1;
                }
            }
        }

        int regionCount = 0;

        // Perform DFS to find connected regions
        for (int row = 0; row < gridSize * 3; ++row) {
            for (int col = 0; col < gridSize * 3; ++col) {
                if (upscaledGrid[row][col] == 0) {
                    dfs(upscaledGrid, row, col);
                    ++regionCount;
                }
            }
        }

        return regionCount;
    }

private:
    void dfs(vector<vector<int>>& upscaledGrid, int row, int col) {
        // Boundary and visited checks
        if (row < 0 || row == upscaledGrid.size() || col < 0 || col == upscaledGrid[0].size()) {
            return;
        }
        if (upscaledGrid[row][col] != 0) {
            return;
        }

        upscaledGrid[row][col] = 2;  // Mark as visited
        dfs(upscaledGrid, row + 1, col);  // Down
        dfs(upscaledGrid, row - 1, col);  // Up
        dfs(upscaledGrid, row, col + 1);  // Right
        dfs(upscaledGrid, row, col - 1);  // Left
    }
};
