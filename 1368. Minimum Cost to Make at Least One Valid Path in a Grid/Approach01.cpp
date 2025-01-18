#include <vector>
#include <queue>
#include <utility>

class Solution {
 public:
  int minCost(std::vector<std::vector<int>>& grid) {
    const int rows = grid.size();
    const int cols = grid[0].size();
    std::vector<std::vector<int>> costMemo(rows, std::vector<int>(cols, -1));
    std::queue<std::pair<int, int>> bfsQueue;

    // Start DFS from the top-left corner with an initial cost of 0
    dfs(grid, 0, 0, 0, bfsQueue, costMemo);

    // Process the BFS queue to explore all possible paths
    for (int currentCost = 1; !bfsQueue.empty(); ++currentCost) {
      for (int size = bfsQueue.size(); size > 0; --size) {
        const auto [currentRow, currentCol] = bfsQueue.front();
        bfsQueue.pop();
        for (const auto& [dx, dy] : directions)
          dfs(grid, currentRow + dx, currentCol + dy, currentCost, bfsQueue, costMemo);
      }
    }

    // Return the minimum cost to reach the bottom-right corner
    return costMemo.back().back();
  }

 private:
  // Directions: right, left, down, up
  static constexpr int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  void dfs(const std::vector<std::vector<int>>& grid, int row, int col, int currentCost,
           std::queue<std::pair<int, int>>& bfsQueue, std::vector<std::vector<int>>& costMemo) {
    // Check for out-of-bounds indices
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
      return;
    // If this cell has already been visited with a lower cost, skip it
    if (costMemo[row][col] != -1)
      return;

    // Mark the current cell with the current cost
    costMemo[row][col] = currentCost;
    // Add the current cell to the BFS queue
    bfsQueue.emplace(row, col);

    // Move in the direction indicated by the current cell's value
    const auto& [dx, dy] = directions[grid[row][col] - 1];
    dfs(grid, row + dx, col + dy, currentCost, bfsQueue, costMemo);
  }
};
