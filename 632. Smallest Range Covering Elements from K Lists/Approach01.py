from typing import *
import heapq

class Solution:
    def smallestRange(self, numLists: list[list[int]]) -> list[int]:
        minHeap = [(row[0], i, 0) for i, row in enumerate(numLists)]
        heapq.heapify(minHeap)

        currentMax = max(row[0] for row in numLists)
        currentMin = heapq.nsmallest(1, minHeap)[0][0]
        result = [currentMin, currentMax]

        while len(minHeap) == len(numLists):
            currentValue, rowIndex, colIndex = heapq.heappop(minHeap)
            if colIndex + 1 < len(numLists[rowIndex]):
                heapq.heappush(minHeap, (numLists[rowIndex][colIndex + 1], rowIndex, colIndex + 1))
                currentMax = max(currentMax, numLists[rowIndex][colIndex + 1])
                currentMin = heapq.nsmallest(1, minHeap)[0][0]
                if currentMax - currentMin < result[1] - result[0]:
                    result[0], result[1] = currentMin, currentMax

        return result