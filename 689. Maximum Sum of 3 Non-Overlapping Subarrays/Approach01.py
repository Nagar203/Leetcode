from typing import List

class Solution:
    def calculateSubArraySums(self, nums: List[int], subArraySize: int) -> List[int]:
        currentSum = 0
        subArraySums = []

        for i in range(len(nums)):
            currentSum += nums[i]

            # Start forming subarrays after the first subArraySize elements
            if i >= subArraySize - 1:
                subArraySums.append(currentSum)
                currentSum -= nums[i - subArraySize + 1]

        return subArraySums

    def calculateMaxSum(self, remainingCount: int, startIndex: int, subArraySize: int, subArraySums: List[int], dp: List[List[int]]) -> int:
        if startIndex >= len(subArraySums) or remainingCount == 0:
            return 0

        if dp[remainingCount][startIndex] != -1:
            return dp[remainingCount][startIndex]

        # Include current subarray
        includeCurrent = subArraySums[startIndex] + self.calculateMaxSum(remainingCount - 1, startIndex + subArraySize, subArraySize, subArraySums, dp)

        # Skip current subarray
        excludeCurrent = self.calculateMaxSum(remainingCount, startIndex + 1, subArraySize, subArraySums, dp)

        dp[remainingCount][startIndex] = max(includeCurrent, excludeCurrent)
        return dp[remainingCount][startIndex]

    def solve(self, subArraySize: int, remainingCount: int, currentIndex: int, resultIndices: List[int], subArraySums: List[int], dp: List[List[int]]):
        while remainingCount > 0 and currentIndex < len(subArraySums):
            includeCurrent = subArraySums[currentIndex] + self.calculateMaxSum(remainingCount - 1, currentIndex + subArraySize, subArraySize, subArraySums, dp)
            excludeCurrent = self.calculateMaxSum(remainingCount, currentIndex + 1, subArraySize, subArraySums, dp)

            if includeCurrent >= excludeCurrent:
                resultIndices.append(currentIndex)
                remainingCount -= 1
                currentIndex += subArraySize
            else:
                currentIndex += 1

    def maxSumOfThreeSubarrays(self, nums: List[int], subArraySize: int) -> List[int]:
        resultIndices = []
        subArraySums = self.calculateSubArraySums(nums, subArraySize)
        n = len(subArraySums)
        dp = [[-1] * n for _ in range(4)]  # 4 rows for up to 3 subarrays + base case

        self.solve(subArraySize, 3, 0, resultIndices, subArraySums, dp)
        return resultIndices