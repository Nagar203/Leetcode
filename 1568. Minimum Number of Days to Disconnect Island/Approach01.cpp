#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Direction vector for traversing the grid in four directions (up, right, down, left).
    const vector<int> directions = {-1, 0, 1, 0, -1};
    // Variables to store the number of rows and columns in the grid.
    int numRows, numCols;

    // Function to determine the minimum number of days required to disconnect the grid.
    int minDays(vector<vector<int>>& grid) {
        // Initialize grid dimensions.
        numRows = grid.size();
        numCols = grid[0].size();
      
        // Check if the grid is already disconnected or completely connected.
        if (countIslands(grid) != 1) {
            return 0;  // No day required if the grid is already disconnected.
        }
      
        // Try removing each land cell to see if it isolates the grid.
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                if (grid[row][col] == 1) {  // Check if the current cell is land.
                    grid[row][col] = 0;  // Temporarily remove the land cell.
                    if (countIslands(grid) != 1) {
                        return 1;  // If removing the cell disconnects the grid, return 1 day.
                    }
                    grid[row][col] = 1;  // Restore the land cell.
                }
            }
        }
      
        // If no single removal disconnects the grid, return 2 days as the required time.
        return 2;
    }

private:
    // Helper function to count the number of islands (connected land components) in the grid.
    int countIslands(vector<vector<int>>& grid) {
        int islandCount = 0;
        // Traverse the grid to identify islands.
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                if (grid[row][col] == 1) {  // Start DFS if a land cell is found.
                    dfs(row, col, grid);
                    ++islandCount;  // Increment the island count after completing DFS.
                }
            }
        }
        // Reset the grid to its original state after counting.
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                if (grid[row][col] == 2) {
                    grid[row][col] = 1;  // Restore the state from temporary 2 to land (1).
                }
            }
        }
        return islandCount;  // Return the total number of islands.
    }

    // Depth-first search (DFS) to mark all cells of a connected component.
    void dfs(int row, int col, vector<vector<int>>& grid) {
        grid[row][col] = 2;  // Temporarily mark the cell to avoid revisiting.
        // Explore all four adjacent directions.
        for (int dir = 0; dir < 4; ++dir) {
            int newRow = row + directions[dir], newCol = col + directions[dir + 1];
            // Continue DFS if the adjacent cell is within bounds and is land.
            if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols && grid[newRow][newCol] == 1) {
                dfs(newRow, newCol, grid);
            }
        }
    }
};
