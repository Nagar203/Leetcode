from typing import *

class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        result = 0
        for n in arr:
            if(n%2 != 0):
                result += 1
            else:
                result = 0
            if(result == 3):
                return True
        return False