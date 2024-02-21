from typing import *

class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        result, shift = 0, 0

        while(left<right):
            left >>= 1
            right >>= 1
            shift += 1
        result = left<<shift
        return result