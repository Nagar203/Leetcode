class Solution:
    def findTargetSumWays(self, numbers: list[int], targetSum: int) -> int:
        totalSum = sum(numbers)

        # Check if the targetSum is achievable
        if totalSum < abs(targetSum) or (totalSum + targetSum) % 2 == 1:
            return 0

        def knapsack(subsetSum: int) -> int:
            # dp[i]: Number of ways to sum to i using numbers so far
            dp = [1] + [0] * totalSum

            for num in numbers:
                for j in range(totalSum, num - 1, -1):
                    dp[j] += dp[j - num]

            return dp[subsetSum]

        subsetSum = (totalSum + targetSum) // 2
        return knapsack(subsetSum)