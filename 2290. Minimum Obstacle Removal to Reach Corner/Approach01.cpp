class Solution {
 public:
  int minimumObstacles(vector<vector<int>>& grid) {
    const int rows = grid.size();
    const int cols = grid[0].size();
    constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    using Cell = tuple<int, int, int>;  // (distance, row, col)
    priority_queue<Cell, vector<Cell>, greater<>> minHeap;
    vector<vector<int>> minDistance(rows, vector<int>(cols, INT_MAX));

    minHeap.emplace(grid[0][0], 0, 0);
    minDistance[0][0] = grid[0][0];

    while (!minHeap.empty()) {
      const auto [currentDistance, currentRow, currentCol] = minHeap.top();
      minHeap.pop();

      if (currentRow == rows - 1 && currentCol == cols - 1)
        return currentDistance;

      for (const auto& [dx, dy] : directions) {
        const int nextRow = currentRow + dx;
        const int nextCol = currentCol + dy;

        if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols)
          continue;

        const int newDistance = currentDistance + grid[nextRow][nextCol];
        if (newDistance < minDistance[nextRow][nextCol]) {
          minDistance[nextRow][nextCol] = newDistance;
          minHeap.emplace(newDistance, nextRow, nextCol);
        }
      }
    }

    return minDistance[rows - 1][cols - 1];
  }
};