#include <vector>
#include <algorithm>
#include <ranges>

class Solution {
 public:
  long long maxPoints(std::vector<std::vector<int>>& points) {
    const int numCols = points[0].size();
    // dp[currentCol] := the maximum number of points you can have if points[i][currentCol] is the
    // most recent cell you picked
    std::vector<long> maxPointsForColumn(numCols);

    for (const std::vector<int>& row : points) {
      std::vector<long> maxPointsFromLeft(numCols);
      long currentMax = 0;

      // Calculate maximum points moving left to right
      for (int col = 0; col < numCols; ++col) {
        currentMax = std::max(currentMax - 1, maxPointsForColumn[col]);
        maxPointsFromLeft[col] = currentMax;
      }

      std::vector<long> maxPointsFromRight(numCols);
      currentMax = 0;

      // Calculate maximum points moving right to left
      for (int col = numCols - 1; col >= 0; --col) {
        currentMax = std::max(currentMax - 1, maxPointsForColumn[col]);
        maxPointsFromRight[col] = currentMax;
      }

      // Update the maximum points for each column considering both directions
      for (int col = 0; col < numCols; ++col)
        maxPointsForColumn[col] = std::max(maxPointsFromLeft[col], maxPointsFromRight[col]) + row[col];
    }

    return *std::ranges::max_element(maxPointsForColumn);
  }
};