from typing import *

class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        n = len(deck)
        result = [0] * n
        skip = False
        i = 0
        j = 0

        deck.sort()

        while i < n:
            if result[j] == 0:
                if not skip:
                    result[j] = deck[i]
                    i += 1
                skip = not skip
            j = (j + 1) % n

        return result