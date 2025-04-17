from typing import List
from collections import defaultdict

class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        numberToIndices = defaultdict(list)

        for index, number in enumerate(nums):
            numberToIndices[number].append(index)

        validPairCount = 0
        for indices in numberToIndices.values():
            indexCount = len(indices)
            for i in range(indexCount - 1):
                for j in range(i + 1, indexCount):
                    if (indices[i] * indices[j]) % k == 0:
                        validPairCount += 1

        return validPairCount