struct Cell {
  int row;
  int col;
  int height;  // heightMap[row][col] or the height after filling water
};

class Solution {
 public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int rows = heightMap.size();
    const int cols = heightMap[0].size();
    int totalWater = 0;
    auto compare = [](const Cell& a, const Cell& b) { return a.height > b.height; };
    priority_queue<Cell, vector<Cell>, decltype(compare)> minHeap(compare);
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // Push boundary cells into the min-heap and mark them as visited
    for (int i = 0; i < rows; ++i) {
      minHeap.emplace(Cell{i, 0, heightMap[i][0]});
      minHeap.emplace(Cell{i, cols - 1, heightMap[i][cols - 1]});
      visited[i][0] = true;
      visited[i][cols - 1] = true;
    }

    for (int j = 1; j < cols - 1; ++j) {
      minHeap.emplace(Cell{0, j, heightMap[0][j]});
      minHeap.emplace(Cell{rows - 1, j, heightMap[rows - 1][j]});
      visited[0][j] = true;
      visited[rows - 1][j] = true;
    }

    // Process the heap
    while (!minHeap.empty()) {
      const auto [row, col, height] = minHeap.top();
      minHeap.pop();
      for (const auto& [dx, dy] : directions) {
        const int newRow = row + dx;
        const int newCol = col + dy;
        if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols)
          continue;
        if (visited[newRow][newCol])
          continue;
        if (heightMap[newRow][newCol] < height) {
          totalWater += height - heightMap[newRow][newCol];  // Water trapped
          minHeap.emplace(Cell{newRow, newCol, height});  // Update height
        } else {
          minHeap.emplace(Cell{newRow, newCol, heightMap[newRow][newCol]});
        }
        visited[newRow][newCol] = true;
      }
    }

    return totalWater;
  }
};