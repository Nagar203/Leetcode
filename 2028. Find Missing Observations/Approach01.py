from typing import *

class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        targetSum = (len(rolls) + n)*mean
        missingSum = targetSum - sum(rolls)

        if(missingSum > (n*6) or missingSum < n):
            return []
        
        result = [missingSum//n]*n
        missingSum %= n

        for i in range(missingSum):
            result[i] += 1
        return result