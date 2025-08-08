class Solution:
    def soupServings(self, totalSoup: int) -> float:
        return 1.0 if totalSoup >= 4800 else self.dfs((totalSoup + 24) // 25, (totalSoup + 24) // 25)

    def __init__(self):
        self.memo = [[0.0] * (4800 // 25) for _ in range(4800 // 25)]

    def dfs(self, soupA: int, soupB: int) -> float:
        if soupA <= 0 and soupB <= 0:
            return 0.5
        if soupA <= 0:
            return 1.0
        if soupB <= 0:
            return 0.0
        if self.memo[soupA][soupB] > 0:
            return self.memo[soupA][soupB]
        self.memo[soupA][soupB] = 0.25 * (
            self.dfs(soupA - 4, soupB) +
            self.dfs(soupA - 3, soupB - 1) +
            self.dfs(soupA - 2, soupB - 2) +
            self.dfs(soupA - 1, soupB - 3)
        )
        return self.memo[soupA][soupB]
