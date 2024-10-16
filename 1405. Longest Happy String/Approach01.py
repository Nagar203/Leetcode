from typing import *

class Solution:
    def longestDiverseString(self, countA: int, countB: int, countC: int, charA: str = 'a', charB: str = 'b', charC: str = 'c') -> str:
        if countA < countB:
            return self.longestDiverseString(countB, countA, countC, charB, charA, charC)
        if countB < countC:
            return self.longestDiverseString(countA, countC, countB, charA, charC, charB)
        if countB == 0:
            return charA * min(countA, 2)

        useCharA = min(countA, 2)
        useCharB = 1 if countA - useCharA >= countB else 0

        return (charA * useCharA) + (charB * useCharB) + self.longestDiverseString(countA - useCharA, countB - useCharB, countC, charA, charB, charC)