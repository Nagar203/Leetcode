from typing import *

class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        
        if(c == 0):
            return True
        
        limit = math.floor(c**(1/2))

        for i in range(1, limit+1):
            a = i*i
            data = c - a
            b = (data**(1/2))
            b = math.floor(b)

            print(a)
            print(b)
            if((a + b*b) == c):
                return True
        return False