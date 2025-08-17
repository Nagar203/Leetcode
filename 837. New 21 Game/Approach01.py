class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        if k == 0 or n >= k - 1 + maxPts:
            return 1.0

        probabilitySum = 0.0
        dp = [0.0] * (n + 1)  # dp[i] = probability of having exactly i points
        dp[0] = 1.0
        slidingWindowSum = dp[0]  # rolling sum for probabilities

        for points in range(1, n + 1):
            dp[points] = slidingWindowSum / maxPts

            if points < k:
                slidingWindowSum += dp[points]
            else:
                probabilitySum += dp[points]

            if points - maxPts >= 0:
                slidingWindowSum -= dp[points - maxPts]

        return probabilitySum
