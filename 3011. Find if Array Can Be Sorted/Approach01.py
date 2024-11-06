from typing import List

class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        previousSetBits = 0
        previousMax = float('-inf')  # The maximum of the previous segment
        currentMax = float('-inf')   # The maximum of the current segment
        currentMin = float('inf')    # The minimum of the current segment

        for number in nums:
            setBitsCount = bin(number).count('1')
            if setBitsCount != previousSetBits:  # Start a new segment
                if previousMax > currentMin:
                    return False
                previousSetBits = setBitsCount
                previousMax = currentMax
                currentMax = number
                currentMin = number
            else:  # Continue with the current segment
                currentMax = max(currentMax, number)
                currentMin = min(currentMin, number)

        return previousMax <= currentMin