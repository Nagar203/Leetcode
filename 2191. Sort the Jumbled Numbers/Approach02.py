from typing import List, Dict
from collections import defaultdict

class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        sortedNums = []
        mappedToOriginalNums = defaultdict(list)  # Dictionary to store mapped value to original numbers

        # Map each number to its corresponding value and store in a dictionary
        for num in nums:
            mappedValue = self.getMappedValue(num, mapping)
            mappedToOriginalNums[mappedValue].append(num)

        # Collect the original numbers in sorted order of their mapped values
        for mappedValue in sorted(mappedToOriginalNums.keys()):
            sortedNums.extend(mappedToOriginalNums[mappedValue])

        return sortedNums

    # Function to get the mapped value of a number based on the provided mapping
    def getMappedValue(self, num: int, mapping: List[int]) -> int:
        mappedString = ''.join(str(mapping[int(digit)]) for digit in str(num))
        return int(mappedString)
