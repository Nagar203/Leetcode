from typing import *

class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        if n == 0 or s[0] == '0':
            return 0
    
        dp = [0] * n
        dp[0] = 1

        for i in range(1, n):
            if s[i] != '0':
                dp[i] = dp[i - 1]

            two_digit = int(s[i - 1:i + 1])
            if 10 <= two_digit <= 26:
                dp[i] += dp[i - 2] if i >= 2 else 1

        return dp[n - 1]