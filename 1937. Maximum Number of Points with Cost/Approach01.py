from typing import List

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        numCols = len(points[0])
        # maxPointsForColumn[col] := the maximum number of points you can have if points[i][col] is the
        # most recent cell you picked
        maxPointsForColumn = [0] * numCols

        for row in points:
            maxPointsFromLeft = [0] * numCols
            currentMax = 0

            # Calculate maximum points moving left to right
            for col in range(numCols):
                currentMax = max(currentMax - 1, maxPointsForColumn[col])
                maxPointsFromLeft[col] = currentMax

            maxPointsFromRight = [0] * numCols
            currentMax = 0

            # Calculate maximum points moving right to left
            for col in range(numCols - 1, -1, -1):
                currentMax = max(currentMax - 1, maxPointsForColumn[col])
                maxPointsFromRight[col] = currentMax

            # Update the maximum points for each column considering both directions
            for col in range(numCols):
                maxPointsForColumn[col] = max(maxPointsFromLeft[col], maxPointsFromRight[col]) + row[col]

        return max(maxPointsForColumn)