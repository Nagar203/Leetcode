from typing import *

class Solution:
    def longestSquareStreak(self, numbers: list[int]) -> int:
        # Remove duplicates and sort in descending order
        numbers = sorted(set(numbers), reverse=True)

        maxNumber = max(numbers)
        # dp[i] represents the longest square streak starting with i
        dp = [0] * (maxNumber + 1)

        for number in numbers:
            dp[number] = 1
            squaredNumber = number * number
            if squaredNumber <= maxNumber:
                dp[number] += dp[squaredNumber]

        result = max(dp)
        return -1 if result < 2 else result