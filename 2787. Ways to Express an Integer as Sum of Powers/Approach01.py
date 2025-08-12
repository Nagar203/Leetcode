class Solution:
    def numberOfWays(self, targetSum: int, power: int) -> int:
        MOD = 1_000_000_007
        dp = [0] * (targetSum + 1)
        dp[0] = 1

        baseNumber = 1
        while (powerValue := baseNumber ** power) <= targetSum:
            for currentSum in range(targetSum, powerValue - 1, -1):
                dp[currentSum] = (dp[currentSum] + dp[currentSum - powerValue]) % MOD
            baseNumber += 1

        return dp[targetSum]
