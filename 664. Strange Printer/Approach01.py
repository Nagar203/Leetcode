from typing import *

class Solution:
    def strangePrinter(self, s: str) -> int:
        length = len(s)
        memo = [[0] * length for _ in range(length)]
        
        # Start the recursive function to find the minimum number of turns
        # needed to print the entire string.
        return self.findMinTurns(s, 0, length - 1, memo)

    def findMinTurns(self, s: str, start: int, end: int, memo: list[list[int]]) -> int:
        # Base case: if the start index exceeds the end index, no turns are needed.
        if start > end:
            return 0
        
        # If the result for this substring has already been computed, return the cached result.
        if memo[start][end] > 0:
            return memo[start][end]

        # Initialize the minimum turns by assuming we print the character at 'start' separately.
        memo[start][end] = self.findMinTurns(s, start + 1, end, memo) + 1

        # Try to find any matching characters within the range to optimize the number of turns.
        for mid in range(start + 1, end + 1):
            # If s[mid] matches s[start], consider this as a candidate for reducing the number of turns.
            if s[mid] == s[start]:
                memo[start][end] = min(memo[start][end], self.findMinTurns(s, start, mid - 1, memo) + self.findMinTurns(s, mid + 1, end, memo))

        # Return the minimum number of turns required to print the substring s[start..end].
        return memo[start][end]