from typing import List

class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        prefixSum = [0]

        for diff in differences:
            prefixSum.append(prefixSum[-1] + diff)

        maxPrefix = max(prefixSum)
        minPrefix = min(prefixSum)

        return max(0, (upper - lower) - (maxPrefix - minPrefix) + 1)