#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> spiralMatrixIII(int numRows, int numCols, int startRow, int startCol) {
    // Direction vectors: right, down, left, up
    const vector<int> xDirections{1, 0, -1, 0};
    const vector<int> yDirections{0, 1, 0, -1};
    
    // Resultant matrix with the starting point
    vector<vector<int>> result{{startRow, startCol}};

    // Loop until we fill the matrix
    for (int i = 0; result.size() < numRows * numCols; ++i) {
      for (int step = 0; step < i / 2 + 1; ++step) {
        // Move in the current direction
        startRow += yDirections[i % 4];
        startCol += xDirections[i % 4];
        
        // Check if the new position is within the bounds
        if (0 <= startRow && startRow < numRows && 0 <= startCol && startCol < numCols) {
          result.push_back({startRow, startCol});
        }
      }
    }

    return result;
  }
};
