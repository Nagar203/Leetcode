from typing import List

class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        maxXorValue = (1 << maximumBit) - 1  # Maximum value with all bits set to 1
        result = []
        cumulativeXor = 0

        for num in nums:
            cumulativeXor ^= num
            result.append(cumulativeXor ^ maxXorValue)

        # Reverse the result list to match the required order
        result.reverse()
        return result