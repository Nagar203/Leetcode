from typing import List
from collections import Counter

class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        arraySize = len(nums)
        leftFrequency = Counter()  
        rightFrequency = Counter(nums)

        for i, num in enumerate(nums):
            leftFrequency[num] += 1
            rightFrequency[num] -= 1

            leftCount = leftFrequency[num]
            rightCount = rightFrequency[num]
            
            if leftCount * 2 > i + 1 and rightCount * 2 > arraySize - 1 - i:
                return i

        return -1
