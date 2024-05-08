from collections import defaultdict
from typing import *
class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        sorted_score = sorted(score, reverse=True)
        rank_map = defaultdict()

        medals = ["Gold Medal", "Silver Medal", "Bronze Medal"]
        result = []

        for i, s in enumerate(sorted_score):
            rank_map[s] = i + 1

        for s in score:
            rank = rank_map[s]
            if rank <= 3:
                result.append(medals[rank - 1])
            else:
                result.append(str(rank))

        return result
