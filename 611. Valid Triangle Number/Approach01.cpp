class Solution {
 public:
  int triangleNumber(vector<int>& sideLengths) {
    if (sideLengths.size() < 3)
      return 0;

    int validTriangleCount = 0;

    ranges::sort(sideLengths);

    for (int largestIndex = sideLengths.size() - 1; largestIndex > 1; --largestIndex) {
      int leftIndex = 0;
      int rightIndex = largestIndex - 1;
      while (leftIndex < rightIndex)
        if (sideLengths[leftIndex] + sideLengths[rightIndex] > sideLengths[largestIndex]) {
          validTriangleCount += rightIndex - leftIndex;
          --rightIndex;
        } else {
          ++leftIndex;
        }
    }

    return validTriangleCount;
  }
};
