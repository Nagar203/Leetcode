from typing import *

class Solution:
    def minimumDeletions(self, s: str) -> int:
        minDeletions = 0  # Minimum deletions to make the string balanced
        countB = 0        # Count of 'b's encountered so far

        for c in s:
            if c == 'a':
                # Either delete this 'a' or keep it and delete some 'b's seen before
                minDeletions = min(minDeletions + 1, countB)
            else:
                countB += 1  # Increment count of 'b's

        return minDeletions
