class Solution:
    MOD = 1000000007

    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        # Initialize the dp array
        dp = [0] * (high + 1)
        dp[0] = 1  # Base case: 1 way to create a string of length 0

        # Fill the dp array
        for length in range(1, high + 1):
            if length >= zero:  # Add strings ending with `zero`
                dp[length] = (dp[length] + dp[length - zero]) % self.MOD
            if length >= one:  # Add strings ending with `one`
                dp[length] = (dp[length] + dp[length - one]) % self.MOD

        # Calculate the result for lengths within [low, high]
        result = 0
        for length in range(low, high + 1):
            result = (result + dp[length]) % self.MOD

        return result