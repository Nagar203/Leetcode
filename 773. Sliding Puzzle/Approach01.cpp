#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <array>
#include <algorithm>
using namespace std;

class Solution {
 public:
  int slidingPuzzle(vector<vector<int>>& board) {
    constexpr array<array<int, 2>, 4> directions = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
    constexpr int rows = 2;
    constexpr int cols = 3;
    const string targetState = "123450";
    string initialState;

    // Convert the 2D board into a string representation
    for (int row = 0; row < rows; ++row)
      for (int col = 0; col < cols; ++col)
        initialState += '0' + board[row][col];

    if (initialState == targetState)
      return 0;

    queue<string> stateQueue{{initialState}};
    unordered_set<string> visitedStates{initialState};

    for (int steps = 1; !stateQueue.empty(); ++steps) {
      for (int currentLevelSize = stateQueue.size(); currentLevelSize > 0; --currentLevelSize) {
        string currentState = stateQueue.front();
        stateQueue.pop();
        const int zeroIndex = currentState.find('0');
        const int zeroRow = zeroIndex / cols;
        const int zeroCol = zeroIndex % cols;

        for (const auto& [dx, dy] : directions) {
          const int newRow = zeroRow + dx;
          const int newCol = zeroCol + dy;

          if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols)
            continue;

          const int swapIndex = newRow * cols + newCol;
          swap(currentState[zeroIndex], currentState[swapIndex]);

          if (currentState == targetState)
            return steps;

          if (!visitedStates.count(currentState)) {
            stateQueue.push(currentState);
            visitedStates.insert(currentState);
          }

          swap(currentState[zeroIndex], currentState[swapIndex]);
        }
      }
    }

    return -1;
  }
};