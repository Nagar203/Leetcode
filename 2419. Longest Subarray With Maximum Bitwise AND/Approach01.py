from typing import *

class Solution:
    def longestSubarray(self, nums):
        maxLength = 0  # To store the maximum length of subarray
        maxElementIndex = 0  # To track the index of the maximum element found
        currentStreakLength = 0  # Length of the current streak of the maximum element

        for i in range(len(nums)):
            if nums[i] == nums[maxElementIndex]:
                currentStreakLength += 1
                maxLength = max(maxLength, currentStreakLength)  # Update the max length
            elif nums[i] > nums[maxElementIndex]:
                maxElementIndex = i  # Update the index of the new maximum element
                currentStreakLength = 1  # Reset the streak length to 1 for the new element
                maxLength = 1  # Reset the max length to 1
            else:
                currentStreakLength = 0  # Reset the streak length if element is less than max

        return maxLength