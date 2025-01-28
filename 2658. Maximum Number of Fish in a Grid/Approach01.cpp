#include <vector>
#include <algorithm>
using namespace std;

class Solution {
 public:
  int findMaxFish(vector<vector<int>>& grid) {
    int maxFish = 0;  // Maximum fish that can be collected

    for (int row = 0; row < grid.size(); ++row) {
      for (int col = 0; col < grid[0].size(); ++col) {
        if (grid[row][col] > 0) {
          maxFish = max(maxFish, performDFS(grid, row, col));
        }
      }
    }

    return maxFish;
  }

 private:
  int performDFS(vector<vector<int>>& grid, int row, int col) {
    // Check for out-of-bounds or water cell (value 0)
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0) {
      return 0;
    }

    int fishCaught = grid[row][col];  // Fish caught at this cell
    grid[row][col] = 0;  // Mark the cell as visited by setting it to 0

    // Recursively collect fish in all four directions
    return fishCaught + 
           performDFS(grid, row + 1, col) +
           performDFS(grid, row - 1, col) +
           performDFS(grid, row, col + 1) +
           performDFS(grid, row, col - 1);
  }
};