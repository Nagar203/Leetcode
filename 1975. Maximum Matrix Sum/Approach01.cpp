#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
 public:
  long long maxMatrixSum(vector<vector<int>>& matrix) {
    long long totalAbsoluteSum = 0;  // Total absolute value sum of elements
    int smallestAbsoluteValue = INT_MAX;  // Smallest absolute value in the matrix
    int isOddNegativeCount = 0;  // 0: Even number of negatives, 1: Odd number of negatives

    for (const vector<int>& row : matrix) {
      for (const int value : row) {
        totalAbsoluteSum += abs(value);
        smallestAbsoluteValue = min(smallestAbsoluteValue, abs(value));
        if (value < 0)
          isOddNegativeCount ^= 1;  // Toggle between 0 and 1
      }
    }

    // Subtract twice the smallest absolute value if the negative count is odd
    return totalAbsoluteSum - isOddNegativeCount * smallestAbsoluteValue * 2;
  }
};