from typing import List

class Solution:
    MOD = 10**9 + 7

    def idealArrays(self, arrayLength: int, maxValue: int) -> int:
        maxSequenceLength = min(14, arrayLength)
        factorList = self.getFactors(maxValue)
        dp = [[0] * (maxValue + 1) for _ in range(maxSequenceLength + 1)]
        combinationMemo = [[-1] * maxSequenceLength for _ in range(arrayLength)]

        totalCount = 0

        for value in range(1, maxValue + 1):
            dp[1][value] = 1

        for length in range(2, maxSequenceLength + 1):
            for value in range(1, maxValue + 1):
                for factor in factorList[value]:
                    dp[length][value] += dp[length - 1][factor]
                    dp[length][value] %= self.MOD

        for length in range(1, maxSequenceLength + 1):
            dp[length][0] = sum(dp[length][1:]) % self.MOD

        for length in range(1, maxSequenceLength + 1):
            totalCount += dp[length][0] * self.computeCombination(arrayLength - 1, length - 1, combinationMemo)
            totalCount %= self.MOD

        return totalCount

    def getFactors(self, maxValue: int) -> List[List[int]]:
        factorList = [[] for _ in range(maxValue + 1)]
        for divisor in range(1, maxValue + 1):
            for multiple in range(divisor * 2, maxValue + 1, divisor):
                factorList[multiple].append(divisor)
        return factorList

    def computeCombination(self, n: int, k: int, memo: List[List[int]]) -> int:
        if k == 0 or n == k:
            return 1
        if memo[n][k] != -1:
            return memo[n][k]
        memo[n][k] = (self.computeCombination(n - 1, k, memo) + self.computeCombination(n - 1, k - 1, memo)) % self.MOD
        return memo[n][k]