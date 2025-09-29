class Solution:
    def minScoreTriangulation(self, vertexValues: list[int]) -> int:
        n = len(vertexValues)
        minScore = [[0] * n for _ in range(n)]

        for endIndex in range(2, n):
            for startIndex in range(endIndex - 2, -1, -1):
                minScore[startIndex][endIndex] = float('inf')
                for middleIndex in range(startIndex + 1, endIndex):
                    minScore[startIndex][endIndex] = min(
                        minScore[startIndex][endIndex],
                        minScore[startIndex][middleIndex] +
                        vertexValues[startIndex] * vertexValues[middleIndex] * vertexValues[endIndex] +
                        minScore[middleIndex][endIndex]
                    )

        return minScore[0][n - 1]