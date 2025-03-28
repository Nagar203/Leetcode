from dataclasses import dataclass
import heapq

@dataclass(frozen=True)
class IndexedQuery:
    queryIndex: int
    queryValue: int
    def __iter__(self):
        yield self.queryIndex
        yield self.queryValue
        
class Solution:
    def maxPoints(self, grid: list[list[int]], queries: list[int]) -> list[int]:
        DIRECTIONS = ((0, 1), (1, 0), (0, -1), (-1, 0))
        rows = len(grid)
        cols = len(grid[0])
        result = [0] * len(queries)
        minHeap = [(grid[0][0], 0, 0)]  
        visitedCells = {(0, 0)}
        pointsCollected = 0
        indexedQueries = sorted(
            [IndexedQuery(i, query) for i, query in enumerate(queries)],
            key=lambda x: x.queryValue
        )
        for queryIndex, queryValue in indexedQueries:
            while minHeap:
                cellValue, rowIndex, colIndex = heapq.heappop(minHeap)
                if cellValue >= queryValue:
                    heapq.heappush(minHeap, (cellValue, rowIndex, colIndex))
                    break
                pointsCollected += 1
                for dRow, dCol in DIRECTIONS:
                    newRow = rowIndex + dRow
                    newCol = colIndex + dCol
                    if newRow < 0 or newRow == rows or newCol < 0 or newCol == cols:
                        continue
                    if (newRow, newCol) in visitedCells:
                        continue
                    heapq.heappush(minHeap, (grid[newRow][newCol], newRow, newCol))
                    visitedCells.add((newRow, newCol))
            result[queryIndex] = pointsCollected
        return result