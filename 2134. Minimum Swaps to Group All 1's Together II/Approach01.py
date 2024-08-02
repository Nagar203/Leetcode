from typing import List

class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        n = len(nums)  # Size of the input list
        totalOnes = nums.count(1)  # Total count of 1s in the input list
        currentOnesInWindow = 0  # The number of 1s in the current window
        maxOnesInWindow = 0  # The maximum number of 1s in any window

        for i in range(n * 2):
            if i >= totalOnes and nums[(i - totalOnes) % n] == 1:
                currentOnesInWindow -= 1  # Remove the element that is sliding out of the window
            if nums[i % n] == 1:
                currentOnesInWindow += 1  # Add the new element sliding into the window
            maxOnesInWindow = max(maxOnesInWindow, currentOnesInWindow)  # Update the maximum number of 1s found in any window

        return totalOnes - maxOnesInWindow  # Minimum swaps required is total 1s minus the maximum 1s in a window
