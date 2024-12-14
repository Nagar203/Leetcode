from typing import List
from collections import deque

class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        result = 0
        left = 0  # Start of the current valid subarray

        max_deque = deque()  # Stores indices of potential maximum elements
        min_deque = deque()  # Stores indices of potential minimum elements

        for right in range(n):
            # Maintain the max deque (decreasing order)
            while max_deque and nums[max_deque[-1]] <= nums[right]:
                max_deque.pop()
            max_deque.append(right)

            # Maintain the min deque (increasing order)
            while min_deque and nums[min_deque[-1]] >= nums[right]:
                min_deque.pop()
            min_deque.append(right)

            # Check if the window is valid
            while nums[max_deque[0]] - nums[min_deque[0]] > 2:
                # Shrink the window from the left
                if max_deque[0] == left:
                    max_deque.popleft()
                if min_deque[0] == left:
                    min_deque.popleft()
                left += 1

            # Add the number of valid subarrays ending at `right`
            result += (right - left + 1)

        return result