class Solution {
 public:
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int rows = isWater.size();
    const int cols = isWater[0].size();
    vector<vector<int>> heights(rows, vector<int>(cols, -1));
    queue<pair<int, int>> cellsToProcess;

    // Initialize queue with all water cells and set their height to 0
    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        if (isWater[row][col] == 1) {
          cellsToProcess.emplace(row, col);
          heights[row][col] = 0;
        }
      }
    }

    // Perform BFS to calculate the height of each land cell
    while (!cellsToProcess.empty()) {
      const auto [currentRow, currentCol] = cellsToProcess.front();
      cellsToProcess.pop();

      for (const auto& [dx, dy] : directions) {
        const int newRow = currentRow + dx;
        const int newCol = currentCol + dy;

        // Skip invalid or already-processed cells
        if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols)
          continue;
        if (heights[newRow][newCol] != -1)
          continue;

        // Set height and add to queue
        heights[newRow][newCol] = heights[currentRow][currentCol] + 1;
        cellsToProcess.emplace(newRow, newCol);
      }
    }

    return heights;
  }
};
