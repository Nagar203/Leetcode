class Solution:
    def longestMonotonicSubarray(self, nums: list[int]) -> int:
        maxLength = 1
        increasingLength = 1
        decreasingLength = 1

        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                increasingLength += 1
                decreasingLength = 1
            elif nums[i] < nums[i - 1]:
                decreasingLength += 1
                increasingLength = 1
            else:
                increasingLength = 1
                decreasingLength = 1

            maxLength = max(maxLength, increasingLength, decreasingLength)

        return maxLength
