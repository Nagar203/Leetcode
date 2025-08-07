class Solution:
    def maxCollectedFruits(self, fruits: list[list[int]]) -> int:
        return (
            self.getTopLeft(fruits)
            + self.getTopRight(fruits)
            + self.getBottomLeft(fruits)
            - 2 * fruits[-1][-1]  # Subtract center cell counted twice
        )

    def getTopLeft(self, fruits: list[list[int]]) -> int:
        n = len(fruits)
        return sum(fruits[i][i] for i in range(n))

    def getTopRight(self, fruits: list[list[int]]) -> int:
        n = len(fruits)
        dp = [[0] * n for _ in range(n)]
        dp[0][n - 1] = fruits[0][n - 1]

        for row in range(n):
            for col in range(n):
                if row >= col and not (row == n - 1 and col == n - 1):
                    continue
                for dx, dy in [(1, -1), (1, 0), (1, 1)]:
                    prevRow = row - dx
                    prevCol = col - dy
                    if not (0 <= prevRow < n and 0 <= prevCol < n):
                        continue
                    if prevRow < prevCol < n - 1 - prevRow:
                        continue
                    dp[row][col] = max(dp[row][col], dp[prevRow][prevCol] + fruits[row][col])

        return dp[n - 1][n - 1]

    def getBottomLeft(self, fruits: list[list[int]]) -> int:
        n = len(fruits)
        dp = [[0] * n for _ in range(n)]
        dp[n - 1][0] = fruits[n - 1][0]

        for col in range(n):
            for row in range(n):
                if row <= col and not (row == n - 1 and col == n - 1):
                    continue
                for dx, dy in [(-1, 1), (0, 1), (1, 1)]:
                    prevRow = row - dx
                    prevCol = col - dy
                    if not (0 <= prevRow < n and 0 <= prevCol < n):
                        continue
                    if prevCol < prevRow < n - 1 - prevCol:
                        continue
                    dp[row][col] = max(dp[row][col], dp[prevRow][prevCol] + fruits[row][col])

        return dp[n - 1][n - 1]
