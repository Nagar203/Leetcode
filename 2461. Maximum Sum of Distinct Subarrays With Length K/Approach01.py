from typing import List

class Solution:
    def maximumSubarraySum(self, nums: List[int], subarraySize: int) -> int:
        maxSum = 0
        currentSum = 0
        uniqueCount = 0
        frequencyMap = {}

        for i in range(len(nums)):
            currentSum += nums[i]

            # Add the current number to the frequency map
            frequencyMap[nums[i]] = frequencyMap.get(nums[i], 0) + 1
            if frequencyMap[nums[i]] == 1:  # New unique element
                uniqueCount += 1

            # Remove the element sliding out of the window
            if i >= subarraySize:
                frequencyMap[nums[i - subarraySize]] -= 1
                if frequencyMap[nums[i - subarraySize]] == 0:
                    uniqueCount -= 1
                currentSum -= nums[i - subarraySize]

            # Check if the current subarray has exactly `subarraySize` unique elements
            if i >= subarraySize - 1 and uniqueCount == subarraySize:
                maxSum = max(maxSum, currentSum)

        return maxSum