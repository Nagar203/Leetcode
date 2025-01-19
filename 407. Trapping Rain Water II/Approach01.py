import heapq

class Solution:
    def trapRainWater(self, heightMap: list[list[int]]) -> int:
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        rows = len(heightMap)
        cols = len(heightMap[0])
        totalWater = 0
        minHeap = []
        visited = [[False] * cols for _ in range(rows)]

        # Push boundary cells into the min-heap and mark them as visited
        for i in range(rows):
            heapq.heappush(minHeap, (heightMap[i][0], i, 0))
            heapq.heappush(minHeap, (heightMap[i][cols - 1], i, cols - 1))
            visited[i][0] = True
            visited[i][cols - 1] = True

        for j in range(1, cols - 1):
            heapq.heappush(minHeap, (heightMap[0][j], 0, j))
            heapq.heappush(minHeap, (heightMap[rows - 1][j], rows - 1, j))
            visited[0][j] = True
            visited[rows - 1][j] = True

        # Process the heap
        while minHeap:
            height, row, col = heapq.heappop(minHeap)
            for dx, dy in directions:
                newRow, newCol = row + dx, col + dy
                if newRow < 0 or newRow >= rows or newCol < 0 or newCol >= cols:
                    continue
                if visited[newRow][newCol]:
                    continue
                if heightMap[newRow][newCol] < height:
                    totalWater += height - heightMap[newRow][newCol]  # Water trapped
                    heapq.heappush(minHeap, (height, newRow, newCol))  # Update height
                else:
                    heapq.heappush(minHeap, (heightMap[newRow][newCol], newRow, newCol))
                visited[newRow][newCol] = True

        return totalWater