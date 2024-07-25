from typing import List

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        countMap = {}  # Dictionary to store the count of each number
        minValue = min(nums)
        maxValue = max(nums)

        # Count the occurrences of each number in the list
        for num in nums:
            if num in countMap:
                countMap[num] += 1
            else:
                countMap[num] = 1

        nums.clear()

        # Reconstruct the sorted list based on the countMap
        for value in range(minValue, maxValue + 1):
            if value in countMap:
                nums.extend([value] * countMap[value])

        return nums
