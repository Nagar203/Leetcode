from typing import *


class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        xors = functools.reduce(operator.xor, nums)
        lowbit = xors & -xors
        result = [0, 0]

        for num in nums:
            if num & lowbit:
                result[0] ^= num
            else:
                result[1] ^= num

        return result
