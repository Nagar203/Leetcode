from typing import List, Tuple

class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        mappedNums = []  # List to store (mappedValue, originalIndex, originalValue)

        # Map each number to its corresponding value and store with its index and original value
        for i, num in enumerate(nums):
            mappedValue = self.getMappedValue(num, mapping)
            mappedNums.append((mappedValue, i, num))

        # Sort the mapped numbers
        mappedNums.sort()

        # Collect the original numbers in sorted order
        sortedNums = [originalValue for mappedValue, index, originalValue in mappedNums]

        return sortedNums

    # Function to get the mapped value of a number based on the provided mapping
    def getMappedValue(self, num: int, mapping: List[int]) -> int:
        mappedString = ''.join(str(mapping[int(digit)]) for digit in str(num))
        return int(mappedString)
