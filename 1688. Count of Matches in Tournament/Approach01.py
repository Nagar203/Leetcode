from typing import List

class Solution:
    def numberOfMatches(self, n: int) -> int:
        matches_played = 0

        while n > 1:
            matches_played += n // 2
            n = (n + 1) // 2

        return matches_played