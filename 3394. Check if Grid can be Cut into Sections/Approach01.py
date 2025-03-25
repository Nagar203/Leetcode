from typing import List

class Solution:
    def checkValidCuts(self, n: int, rectangles: List[List[int]]) -> bool:
        xIntervals = []
        yIntervals = []

        for rectangle in rectangles:
            startX, startY, endX, endY = rectangle
            xIntervals.append((startX, endX))
            yIntervals.append((startY, endY))

        return max(self.countMergedIntervals(xIntervals), self.countMergedIntervals(yIntervals)) >= 3

    def countMergedIntervals(self, intervals: List[tuple]) -> int:
        mergedCount = 0
        previousEnd = 0

        intervals.sort()

        for start, end in intervals:
            if start < previousEnd:
                previousEnd = max(previousEnd, end)
            else:
                previousEnd = end
                mergedCount += 1

        return mergedCount
