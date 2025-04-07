from typing import List

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        totalSum = sum(nums)
        if totalSum % 2 != 0:
            return False
        return self.knapsack(nums, totalSum // 2)

    def knapsack(self, nums: List[int], targetSum: int) -> bool:
        n = len(nums)
        dp = [[False] * (targetSum + 1) for _ in range(n + 1)]
        dp[0][0] = True

        for i in range(1, n + 1):
            currentNum = nums[i - 1]
            for currSum in range(targetSum + 1):
                if currSum < currentNum:
                    dp[i][currSum] = dp[i - 1][currSum]
                else:
                    dp[i][currSum] = dp[i - 1][currSum] or dp[i - 1][currSum - currentNum]

        return dp[n][targetSum]