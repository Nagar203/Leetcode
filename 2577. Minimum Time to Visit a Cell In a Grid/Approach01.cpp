class Solution {
 public:
  int minimumTime(vector<vector<int>>& grid) {
    if (grid[0][1] > 1 && grid[1][0] > 1)
      return -1;

    constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int rows = grid.size();
    const int cols = grid[0].size();
    using Cell = tuple<int, int, int>;  // (currentTime, row, col)
    priority_queue<Cell, vector<Cell>, greater<>> minHeap;
    vector<vector<bool>> visited(rows, vector<bool>(cols));

    minHeap.emplace(0, 0, 0);
    visited[0][0] = true;

    while (!minHeap.empty()) {
      const auto [currentTime, row, col] = minHeap.top();
      minHeap.pop();
      if (row == rows - 1 && col == cols - 1)
        return currentTime;
      for (const auto& [dx, dy] : directions) {
        const int newRow = row + dx;
        const int newCol = col + dy;
        if (newRow < 0 || newRow == rows || newCol < 0 || newCol == cols)
          continue;
        if (visited[newRow][newCol])
          continue;
        const int waitTime = (grid[newRow][newCol] - currentTime) % 2 == 0 ? 1 : 0;
        const int nextTime = max(currentTime + 1, grid[newRow][newCol] + waitTime);
        minHeap.emplace(nextTime, newRow, newCol);
        visited[newRow][newCol] = true;
      }
    }

    throw;
  }
};