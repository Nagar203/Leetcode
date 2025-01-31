class Solution {
 public:
  int largestIsland(vector<vector<int>>& grid) {
    const int rows = grid.size();
    const int cols = grid[0].size();
    int maxIslandSize = 0;
    vector<int> componentSizes{0, 0};  // Sizes of connected components (starting from 2)

    // Assign a unique component ID (starting from 2) to each island and store its size
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (grid[i][j] == 1)
          componentSizes.push_back(paint(grid, i, j, componentSizes.size()));
      }
    }

    // Try converting each 0 into 1 and calculate the largest possible island
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (grid[i][j] == 0) {
          unordered_set<int> neighborIds{
              getComponentId(grid, i + 1, j), getComponentId(grid, i - 1, j),
              getComponentId(grid, i, j + 1), getComponentId(grid, i, j - 1)};
          maxIslandSize = max(maxIslandSize, 1 + getTotalSize(neighborIds, componentSizes));
        }
      }
    }

    return maxIslandSize == 0 ? rows * cols : maxIslandSize;
  }

 private:
  int paint(vector<vector<int>>& grid, int i, int j, int componentId) {
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] != 1)
      return 0;
    grid[i][j] = componentId;
    return 1 + paint(grid, i + 1, j, componentId) + paint(grid, i - 1, j, componentId) +
           paint(grid, i, j + 1, componentId) + paint(grid, i, j - 1, componentId);
  }

  int getComponentId(const vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
      return 0;
    return grid[i][j];
  }

  int getTotalSize(const unordered_set<int>& neighborIds, const vector<int>& componentSizes) {
    int totalSize = 0;
    for (const int componentId : neighborIds)
      totalSize += componentSizes[componentId];
    return totalSize;
  }
};
