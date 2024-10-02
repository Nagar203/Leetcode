from typing import *

class Solution:
    def arrayRankTransform(self, numbers: List[int]) -> List[int]:
        sortedNumbers = sorted(numbers)
        numberRank = {}

        for number in sortedNumbers:
            if number not in numberRank:
                numberRank[number] = len(numberRank) + 1

        return [numberRank[number] for number in numbers]