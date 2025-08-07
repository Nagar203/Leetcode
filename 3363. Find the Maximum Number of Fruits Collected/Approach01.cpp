class Solution {
 public:
  int maxCollectedFruits(vector<vector<int>>& fruits) {
    return getTopLeft(fruits) + getTopRight(fruits) + getBottomLeft(fruits) -
           2 * fruits.back().back();  // Subtract center cell counted twice
  }

 private:
  int getTopLeft(const vector<vector<int>>& fruits) {
    int n = fruits.size();
    int total = 0;
    for (int i = 0; i < n; ++i)
      total += fruits[i][i];
    return total;
  }

  int getTopRight(const vector<vector<int>>& fruits) {
    int n = fruits.size();
    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][n - 1] = fruits[0][n - 1];

    for (int row = 0; row < n; ++row) {
      for (int col = 0; col < n; ++col) {
        if (row >= col && !(row == n - 1 && col == n - 1))
          continue;
        for (const auto& [dx, dy] : vector<pair<int, int>>{{1, -1}, {1, 0}, {1, 1}}) {
          int prevRow = row - dx;
          int prevCol = col - dy;
          if (prevRow < 0 || prevRow >= n || prevCol < 0 || prevCol >= n)
            continue;
          if (prevRow < prevCol && prevCol < n - 1 - prevRow)
            continue;
          dp[row][col] = max(dp[row][col], dp[prevRow][prevCol] + fruits[row][col]);
        }
      }
    }

    return dp[n - 1][n - 1];
  }

  int getBottomLeft(const vector<vector<int>>& fruits) {
    int n = fruits.size();
    vector<vector<int>> dp(n, vector<int>(n));
    dp[n - 1][0] = fruits[n - 1][0];

    for (int col = 0; col < n; ++col) {
      for (int row = 0; row < n; ++row) {
        if (row <= col && !(row == n - 1 && col == n - 1))
          continue;
        for (const auto& [dx, dy] : vector<pair<int, int>>{{-1, 1}, {0, 1}, {1, 1}}) {
          int prevRow = row - dx;
          int prevCol = col - dy;
          if (prevRow < 0 || prevRow >= n || prevCol < 0 || prevCol >= n)
            continue;
          if (prevCol < prevRow && prevRow < n - 1 - prevCol)
            continue;
          dp[row][col] = max(dp[row][col], dp[prevRow][prevCol] + fruits[row][col]);
        }
      }
    }

    return dp[n - 1][n - 1];
  }
};
