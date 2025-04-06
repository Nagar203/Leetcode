from typing import List

class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        totalNums = len(nums)
        nums.sort()

        subsetLength = [1] * totalNums           # Length of divisible subset ending at each index
        previousIndex = [-1] * totalNums         # To reconstruct the subset
        result = []

        maxSubsetLength = 1
        maxSubsetEndIndex = 0

        for i in range(1, totalNums):
            for j in range(i):
                if nums[i] % nums[j] == 0 and subsetLength[i] < subsetLength[j] + 1:
                    subsetLength[i] = subsetLength[j] + 1
                    previousIndex[i] = j

                    if subsetLength[i] > maxSubsetLength:
                        maxSubsetLength = subsetLength[i]
                        maxSubsetEndIndex = i

        # Reconstruct the subset
        while maxSubsetEndIndex != -1:
            result.append(nums[maxSubsetEndIndex])
            maxSubsetEndIndex = previousIndex[maxSubsetEndIndex]

        return result