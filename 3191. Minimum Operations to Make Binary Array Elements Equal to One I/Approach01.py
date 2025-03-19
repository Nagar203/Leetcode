from typing import List

class Solution:
    def minOperations(self, binaryArray: List[int]) -> int:
        arraySize = len(binaryArray)
        operationCount = 0

        for i in range(arraySize - 2):
            if binaryArray[i] == 0:
                binaryArray[i + 1] ^= 1
                binaryArray[i + 2] ^= 1
                operationCount += 1

        return -1 if binaryArray[-1] == 0 or binaryArray[-2] == 0 else operationCount
