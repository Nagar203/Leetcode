class Solution:
    def longestSubarray(self, nums: list[int]) -> int:
        maxLength = 0
        zeroCount = 0
        left = 0

        for right in range(len(nums)):
            if nums[right] == 0:
                zeroCount += 1

            while zeroCount == 2:
                if nums[left] == 0:
                    zeroCount -= 1
                left += 1

            maxLength = max(maxLength, right - left)

        return maxLength
