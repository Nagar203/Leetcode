class Solution {
 public:
  double largestTriangleArea(vector<vector<int>>& points) {
    double maxArea = 0;

    for (const vector<int>& pointA : points)
      for (const vector<int>& pointB : points)
        for (const vector<int>& pointC : points)
          maxArea = max(maxArea, 0.5 * abs((pointB[0] - pointA[0]) * (pointC[1] - pointA[1]) -
                                           (pointC[0] - pointA[0]) * (pointB[1] - pointA[1])));

    return maxArea;
  }
};
