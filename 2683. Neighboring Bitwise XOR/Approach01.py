from typing import List
from functools import reduce
import operator

class Solution:
    def doesValidArrayExist(self, derivedArray: List[int]) -> bool:
        # Calculate the cumulative XOR of all elements in derivedArray
        cumulativeXor = reduce(operator.xor, derivedArray)
        # A valid original array exists if the cumulative XOR is zero
        return cumulativeXor == 0